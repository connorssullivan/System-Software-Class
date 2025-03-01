#! /bin/sh

# Get user input
echo "Eneter a Path: "
read path
echo "Enter a File: "
read file

# Print the file permishions
ls -l "$path/$file"

# Get a serch string
echo "Enter a search string: "
read searchString


# Search occurances and count
grep -o "$searchString" "$path/$file" | wc -l
