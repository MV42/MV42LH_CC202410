#!/bin/bash

# Create the necessary directories
mkdir -p Libc Additionnal Bonus

# Function to sort a file
sort_file() {
    local file_name="$1"
    local function_type="$2"

    mv "$file_name" "$function_type/$file_name"
    echo "Moved $file_name to $function_type"
}

# Libc functions
libc_functions=(
    "ft_isalpha" "ft_isdigit" "ft_isalnum" "ft_isascii" "ft_isprint"
    "ft_strlen" "ft_memset" "ft_bzero" "ft_memcpy" "ft_memmove"
    "ft_strlcpy" "ft_strlcat" "ft_toupper" "ft_tolower" "ft_strchr"
    "ft_strrchr" "ft_strncmp" "ft_memchr" "ft_memcmp" "ft_strnstr"
    "ft_atoi" "ft_calloc" "ft_strdup"
)

# Additionnal functions
additionnal_functions=(
    "ft_substr" "ft_strjoin" "ft_strtrim" "ft_split" "ft_itoa"
    "ft_strmapi" "ft_striteri" "ft_putchar_fd" "ft_putstr_fd"
    "ft_putendl_fd" "ft_putnbr_fd"
)

# Bonus functions
bonus_functions=(
    "ft_lstnew" "ft_lstadd_front" "ft_lstsize" "ft_lstlast"
    "ft_lstadd_back" "ft_lstdelone" "ft_lstclear" "ft_lstiter"
    "ft_lstmap"
)

# Iterate through the files and sort them
for file in *.c; do
    if [ -f "$file" ]; then
        for func in "${libc_functions[@]}"; do
            if [ "${file%.*}" == "$func" ]; then
                sort_file "$file" "Libc"
                break
            fi
        done

        for func in "${additionnal_functions[@]}"; do
            if [ "${file%.*}" == "$func" ]; then
                sort_file "$file" "Additionnal"
                break
            fi
        done

        for func in "${bonus_functions[@]}"; do
            if [ "${file%.*}" == "$func" ]; then
                sort_file "$file" "Bonus"
                break
            fi
        done
    fi
done
