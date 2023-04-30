#ifndef PROGRESS_H
# define PROGRESS_H

# include <stdio.h>
# include <sys/time.h>
# include <unistd.h>

// Structure to hold progress bar information
typedef struct	s_progress
{
	int		total;
	int		count;
	int		size;
	double	average_time;
	double	last_time;
	double	total_time;
}				t_progress;

t_progress	create_progress(int total, int size);
void		update_progress(t_progress	*progress, int x);
#endif