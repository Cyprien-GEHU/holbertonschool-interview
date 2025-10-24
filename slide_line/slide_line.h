#ifndef SIDELINE_H
#define SIDELINE_H

#define SLIDE_LEFT 0
#define SLIDE_RIGHT 1

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int slide_line(int *line, size_t size, int direction);

#endif
