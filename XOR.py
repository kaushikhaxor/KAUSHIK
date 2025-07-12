def xor_encrypt(data, key=0x5A):
    # Encrypts data using XOR with the provided key
    return [ord(char) ^ key for char in data]

def format_for_cpp(byte_list):
    # Converts the byte list to a C++ array format string
    return ', '.join(f'0x{b:02X}' for b in byte_list)

# User enters the payload URL
original_url = input("Enter the payload URL: ")

# Encrypting the URL
encrypted_url = xor_encrypt(original_url)

# Prepare only the encrypted C++ array for the URL
cpp_code = f"""
const unsigned char encryptedPayloadUrl[] = {{{format_for_cpp(encrypted_url)}}};
"""

# Write the output to a C++ file
with open("encrypted_data.cpp", "w") as file:
    file.write(cpp_code)

print("Encryption complete. The output has been saved to 'encrypted_data.cpp'.")