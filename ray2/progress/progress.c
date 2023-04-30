#include "progress.h"

// Returns the current time in milliseconds
long long	get_msec_now()
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		return (0);
	return	(long long)time.tv_sec * 1000LL + (long long)time.tv_usec / 1000LL;
}

t_progress	create_progress(int total, int size)
{
	t_progress	progress;

	progress.total = total;
	progress.count = 0;
	progress.average_time = 0;
	progress.last_time = get_msec_now();
	progress.total_time = 0;
	progress.size = size;
	return (progress);
}

void	update_progress(t_progress	*progress, int x)
{
	long long	now;
	double		temp;

	now = get_msec_now();

	progress->count++;
	progress->total_time += ((now - progress->last_time) / 1000);
	progress->average_time = progress->total_time / progress->count;
	progress->last_time = now;

	temp = ((double)(x + 1) / (double)progress->total);

	fprintf(stdout, "\r%d%% | ", (int)(temp * 100));
	for (int i = 0; i < (temp * progress->size); i++)
		fprintf(stdout, "█");
	for (int i = 0; i < (progress->size - temp * progress->size); i++)
		fprintf(stdout, " ");
	fprintf(stdout, " | %d / %d [%.2fs<%.2fs, %.2fit/s]", x + 1, progress->total, progress->total_time,
					progress->average_time * progress->total, 1 / progress->average_time);
	fflush(stdout);
}
