#!/bin/bash
gnuplot <<- EOF
	set term png size 1600,900; \
	set output "$1"; \
	plot "$2" with line, "$3" with line;
EOF
