#!/system/bin/sh

echo "╔════════════════════════════════╗"
echo "║      KAUSHIK PREMIUM TOOL      ║"
echo "╚════════════════════════════════╝"

# Step 1: User se input le folder path ka
echo -n "Enter folder path (e.g. /sdcard/Download/SDK): "
read folder

# Check if folder exists
if [ ! -d "$folder" ]; then
    echo "Error: Folder not found!"
    exit 1
fi

# Step 2: Old name (original file prefix)
echo -n "Enter old name to replace (e.g. PUBGM_): "
read oldname

# Step 3: New name (rename file and replace inside)
echo -n "Enter new name (e.g. KAUSHIK_BGMI): "
read newname

# Step 4: Old username inside file
echo -n "Enter old username inside file (e.g. @PUBGM_): "
read olduser

# Step 5: New username to replace (your username)
echo -n "Enter your username (e.g. @Mrkaushikhaxor): "
read newuser

# Step 6: Rename and replace in .hpp and .cpp files
for file in "$folder"/*.{hpp,cpp}; do
    [ -e "$file" ] || continue

    # Replace inside file
    sed -i "s|$olduser|$newuser|g" "$file"

    # Rename file if it matches pattern
    newfile=$(echo "$file" | sed "s|$oldname|$newname|g")
    if [ "$file" != "$newfile" ]; then
        mv "$file" "$newfile"
    fi
done

echo ""
echo "╔════════════════════════════════╗"
echo "║  DONE! All files renamed and   ║"
echo "║  updated by @Mrkaushikhaxor    ║"
echo "╚════════════════════════════════╝"