#!/bin/bash

HEADER_FILE="libft.h"

create_header() {
    echo "#ifndef LIBFT_H" > $HEADER_FILE
    echo "# define LIBFT_H" >> $HEADER_FILE
    echo "" >> $HEADER_FILE
    echo "# include <stddef.h>" >> $HEADER_FILE
    echo "" >> $HEADER_FILE
}

extract_prototypes() {
    local file="$1"
    grep -E '^[a-zA-Z_][a-zA-Z0-9_]*[[:space:]]+[a-zA-Z_][a-zA-Z0-9_]*[[:space:]]*\(.*\)[[:space:]]*' "$file" | sed 's/[[:space:]]*{[[:space:]]*$//;s/^[[:space:]]*//;s/[[:space:]]*$//;s/$/;/'
}

end_header() {
    echo "" >> $HEADER_FILE
    echo "#endif" >> $HEADER_FILE
}

create_header

find . -type f -name "*.c" | while read file; do
    extract_prototypes "$file"
done | sort | uniq >> $HEADER_FILE

end_header