import os
import re

def extract_ascii_strings(data, min_len=4):
    pattern = rb'[\x20-\x7E]{%d,}' % min_len
    return [(m.start(), m.group().decode('ascii')) for m in re.finditer(pattern, data)]

def extract_utf16le_strings(data, min_len=4):
    pattern = (b'(?:[\x20-\x7E]\x00){%d,}' % min_len)
    results = []
    for m in re.finditer(pattern, data):
        try:
            s = m.group().decode('utf-16le')
            results.append((m.start(), s))
        except:
            continue
    return results

def extract_utf16be_strings(data, min_len=4):
    pattern = (b'(?:\x00[\x20-\x7E]){%d,}' % min_len)
    results = []
    for m in re.finditer(pattern, data):
        try:
            s = m.group().decode('utf-16be')
            results.append((m.start(), s))
        except:
            continue
    return results

def extract_all_strings(data):
    ascii_strs = extract_ascii_strings(data)
    utf16le_strs = extract_utf16le_strings(data)
    utf16be_strs = extract_utf16be_strings(data)
    all_strs = ascii_strs + utf16le_strs + utf16be_strs
    all_strs.sort(key=lambda x: x[0])
    return all_strs

def find_strings_by_keyword(strings, keyword):
    keyword_lower = keyword.lower()
    return [(offset, s) for offset, s in strings if keyword_lower in s.lower()]

def find_strings_by_offset(strings, offset, base_address):
    # offset = virtual address, so convert to file offset:
    file_offset = offset - base_address
    if file_offset < 0:
        return []
    matches = []
    for start, s in strings:
        length = len(s.encode('utf-8'))
        if start <= file_offset < start + length:
            matches.append((start, s))
    return matches

def format_offset(offset):
    return f"0x{offset:08X}"

def print_header():
    print("\n=== 🛠️ IDA-like .so String & Offset Finder Tool 🛠️ ===\n")

def main():
    print_header()
    
    path = input("📂 Enter full path to your .so file: ").strip()
    if not os.path.isfile(path):
        print("❌ File not found. Check the path and try again.")
        return
    
    base_address_input = input("🏠 Enter base load address of .so (hex, e.g. 0x100000) or leave empty for 0: ").strip()
    if base_address_input:
        try:
            if base_address_input.startswith("0x") or base_address_input.startswith("0X"):
                base_address = int(base_address_input, 16)
            else:
                base_address = int(base_address_input)
        except:
            print("❌ Invalid base address. Using 0.")
            base_address = 0
    else:
        base_address = 0
    
    print(f"Using base address: {format_offset(base_address)}\n")
    
    print("📦 Loading file and extracting strings (ASCII + UTF-16 LE/BE)... Please wait...")
    with open(path, 'rb') as f:
        data = f.read()
    
    strings = extract_all_strings(data)
    print(f"✅ Extracted total {len(strings)} strings.\n")
    
    print("➡️ You can now search either by string or by offset (hex or decimal).")
    print("Examples:")
    print(" - To search string: socket")
    print(" - To search offset: 0x2441  OR  9281")
    print(" - Type 'exit' to quit.\n")
    
    while True:
        user_input = input("Enter string or offset to search: ").strip()
        if user_input.lower() == 'exit':
            print("👋 Exiting. Bye!")
            break
        
        offset = None
        try:
            if user_input.startswith("0x") or user_input.startswith("0X"):
                offset = int(user_input, 16)
            else:
                if user_input.isdigit():
                    offset = int(user_input)
        except ValueError:
            offset = None
        
        if offset is not None:
            found = find_strings_by_offset(strings, offset, base_address)
            if found:
                print(f"\n🔎 Found {len(found)} string(s) covering offset {format_offset(offset)}:")
                for off, s in found:
                    # Show offset as VA
                    print(f"➡️ Offset: {format_offset(base_address + off)} ({base_address + off}) | String: {s}")
            else:
                print(f"❌ No string found at or covering offset {format_offset(offset)}.")
            print()
        else:
            found = find_strings_by_keyword(strings, user_input)
            if found:
                print(f"\n🔎 Found {len(found)} string(s) containing '{user_input}':")
                for off, s in found:
                    # Show offset as VA
                    print(f"➡️ Offset: {format_offset(base_address + off)} ({base_address + off}) | String: {s}")
            else:
                print(f"❌ No strings found containing '{user_input}'.")
            print()

if __name__ == "__main__":
    main()