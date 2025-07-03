import os
import logging
import time
import traceback
from asyncio import sleep
from telegram import Update, KeyboardButton, ReplyKeyboardMarkup
from telegram.ext import ApplicationBuilder, CommandHandler, MessageHandler, filters, ContextTypes

BOT_TOKEN = "7724266159:AAHFWAoTWYim9Tcv6v049Av23jd5AMPcfts"  # Your bot token

# Setup logging
logging.basicConfig(level=logging.ERROR)


# Function to handle the /start command and display a custom keyboard
async def start(update: Update, context: ContextTypes.DEFAULT_TYPE) -> None:
    user_name = update.message.from_user.first_name  # Get the user's first name


    # Define the custom keyboard layout
    keyboard = [
        [KeyboardButton("🚀 TTF to H"), KeyboardButton("🚀 H to TTF")],
        [KeyboardButton("🚀 PNG to H"), KeyboardButton("🚀 H to PNG")],
    ]
    reply_markup = ReplyKeyboardMarkup(keyboard, resize_keyboard=True)

    # Welcome message
    response = f'''👋 Welcome, {user_name}!
I'm here to assist you with file conversions. 😎

📂 Available conversions:
   - TTF to H
   - H to TTF
   - PNG to H
   - H to PNG

💬 For assistance: @Mrkaushikhaxor
✅ Stay updated: https://t.me/KaushikCracking

Enjoy the experience! 🚀'''

    await update.message.reply_text(response, reply_markup=reply_markup)

# Function to handle keyboard selections
async def handle_keyboard_selection(update: Update, context: ContextTypes.DEFAULT_TYPE) -> None:
    user_choice = update.message.text

    # Handle user selection
    conversion_types = {
        "🚀 TTF to H": "ttf_to_h",
        "🚀 H to TTF": "h_to_ttf",
        "🚀 PNG to H": "png_to_h",
        "🚀 H to PNG": "h_to_png",
    }

    if user_choice in conversion_types:
        context.user_data["conversion_type"] = conversion_types[user_choice]
        await update.message.reply_text(f"✅ You selected: {user_choice}\n📂 Please upload your file to proceed.")
    else:
        await update.message.reply_text("⚠️ Invalid option. Please select a valid conversion type.")

# Function to handle file uploads and initiate conversion
async def handle_file(update: Update, context: ContextTypes.DEFAULT_TYPE) -> None:
    document = update.message.document
    conversion_type = context.user_data.get("conversion_type")

    if not conversion_type:
        await update.message.reply_text(
            "⚠️ Please select a conversion type first using the keyboard options below.",
            reply_markup=ReplyKeyboardMarkup(keyboard, resize_keyboard=True),
        )
        return

    # Determine valid extensions for the selected conversion
    valid_extensions = {
        "ttf_to_h": ".ttf",
        "h_to_ttf": ".h",
        "png_to_h": ".png",
        "h_to_png": ".h",
    }

    input_ext = valid_extensions.get(conversion_type)
    output_ext = {
        ".ttf": ".h",
        ".h": ".ttf",
        ".png": ".h",
        ".h": ".png",
    }.get(input_ext)
    conversion_funcs = {
        "ttf_to_h": convert_ttf_to_h,
        "h_to_ttf": convert_h_to_ttf,
        "png_to_h": convert_png_to_h,
        "h_to_png": convert_h_to_png,
    }

    if document.file_name.endswith(input_ext):
        await process_file(update, context, document, input_ext, output_ext, conversion_funcs[conversion_type])
    else:
        await update.message.reply_text(f"⚠️ Invalid file format. Please upload a file with the `{input_ext}` extension.")

# Function to process the file conversion
async def process_file(update, context, document, input_ext, output_ext, conversion_func):
    try:
        # Notify the user about the process start
        processing_message = await update.message.reply_text(f"🔄 Processing your {input_ext} file... Please wait.")

        # Download the file
        file = await context.bot.get_file(document.file_id)
        input_file_path = document.file_name
        await file.download_to_drive(input_file_path)

        # Simulate processing with animation
        animation = [
            "▰▱▱▱▱▱▱▱ 10% Please Wait...",
            "▰▰▱▱▱▱▱▱▱▱ 20% Please Wait...",
            "▰▰▰▱▱▱▱▱▱▱ 30% Please Wait...",
            "▰▰▰▰▱▱▱▱▱▱ 40% Please Wait...",
            "▰▰▰▰▰▱▱▱▱▱ 50% Halfway There...",
            "▰▰▰▰▰▰▱▱▱▱ 60% Processing...",
            "▰▰▰▰▰▰▰▱▱▱ 70% Almost Done...",
            "▰▰▰▰▰▰▰▰▱▱ 80% Finalizing...",
            "▰▰▰▰▰▰▰▰▰▱ 90% Wrapping Up...",
            "▰▰▰▰▰▰▰▰▰▰ 100% Done!",
        ]

        for frame in animation:
            await sleep(1)  # Non-blocking
            await processing_message.edit_text(f"🔄 {frame}")

        # Convert the file
        output_file_path = input_file_path.replace(input_ext, output_ext)
        conversion_func(input_file_path, output_file_path)

        # Notify the user about the successful conversion
        await processing_message.edit_text("✅ Conversion complete! Your file is ready. Sending now...")

        # Send the converted file back to the user
        await update.message.reply_document(document=open(output_file_path, "rb"))
        await update.message.reply_text(f"🎉 Here is your converted {output_ext} file! Enjoy it! 😁")

        # Clean up temporary files
        if os.path.exists(input_file_path):
            os.remove(input_file_path)
        if os.path.exists(output_file_path):
            os.remove(output_file_path)

        # Show the keyboard again after the conversion is done
        keyboard = [
            [KeyboardButton("🚀 TTF to H"), KeyboardButton("🚀 H to TTF")],
            [KeyboardButton("🚀 PNG to H"), KeyboardButton("🚀 H to PNG")],
        ]
        reply_markup = ReplyKeyboardMarkup(keyboard, resize_keyboard=True)
        await update.message.reply_text("🔁 You can select another conversion option below:", reply_markup=reply_markup)

    except Exception as e:
        logging.error(f"Error occurred: {e}\n{traceback.format_exc()}")
        await update.message.reply_text(f"❌ Network error during file download: {e}")

# TTF to H conversion
def convert_ttf_to_h(input_path: str, output_path: str) -> None:
    with open(input_path, "rb") as ttf_file, open(output_path, "w") as h_file:
        h_file.write("// MADE BY KAUSHIK\n")
        h_file.write("// ANY PROBLEM DM @Mrkaushikhaxor AT TELEGRAM\n\n")
        ttf_data = ttf_file.read()
        size = len(ttf_data)
        num_elements = size // 4
        h_file.write(f"static const unsigned int KAUSHIK_size = {size};\n")
        h_file.write(f"static const unsigned int KAUSHIK_data[{num_elements}] = {{\n")

        for i in range(0, size, 4):
            chunk = ttf_data[i:i + 4]
            value = int.from_bytes(chunk, byteorder='big')
            h_file.write(f"    0x{value:08X},\n")

        h_file.write("};\n")

# H to TTF conversion
def convert_h_to_ttf(input_path: str, output_path: str) -> None:
    with open(input_path, "r") as h_file, open(output_path, "wb") as ttf_file:
        for line in h_file:
            if "0x" in line:
                hex_values = [
                    int(value, 16) for value in line.strip().split(",") if "0x" in value
                ]
                for value in hex_values:
                    ttf_file.write(value.to_bytes(4, byteorder="big"))

# PNG to H conversion
def convert_png_to_h(input_path: str, output_path: str) -> None:
    with open(input_path, "rb") as png_file, open(output_path, "w") as h_file:
        h_file.write(f"// Converted from {input_path}\n")
        h_file.write(f"// MADE BY KAUSHIK\n")
        h_file.write(f"// ANY PROBLEM DM @Mrkaushikhaxor AT TELEGRAM\n\n")
        h_file.write("const unsigned char image_data[] = {\n")
        while chunk := png_file.read(16):
            h_file.write(", ".join(f"0x{byte:02X}" for byte in chunk) + ",\n")
        h_file.write("};\n")
def convert_h_to_png(input_path: str, output_path: str) -> None:
    with open(input_path, "r") as h_file, open(output_path, "wb") as png_file:
        for line in h_file:
            if "0x" in line:
                bytes_data = bytes(int(byte, 16) for byte in line.strip().split(",") if "0x" in byte)
                png_file.write(bytes_data)


# Main function to set up and run the bot
def main():
    app = ApplicationBuilder().token(BOT_TOKEN).build()

    app.add_handler(CommandHandler("start", start))
    app.add_handler(MessageHandler(filters.TEXT & (~filters.COMMAND), handle_keyboard_selection))
    app.add_handler(MessageHandler(filters.Document.ALL, handle_file))  # Ensure this handler is added

    print("Kaushik Bot is running...")
    app.run_polling()

if __name__ == "__main__":
    main()
