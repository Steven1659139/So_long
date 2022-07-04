#!/bin/bash
for file in $(ls test_so_long); do
	echo "$file"
	./so_long "test_so_long/$file"
done
