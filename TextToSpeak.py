import os
from gtts import gTTS
from telegram import Update, ReplyKeyboardMarkup
from telegram.ext import Application, CommandHandler, MessageHandler, filters, ContextTypes

# Telegram Bot Token
TOKEN = "YOUR_TELEGRAM_BOT_TOKEN"

# Dictionary to store user preferences
user_voice_preferences = {}

# Function to generate speech
def text_to_speech(text, gender="female"):
    audio_file = "output.mp3"

    # Adjusting voice settings based on gender
    if gender == "male":
        tts = gTTS(text=text, lang="en", slow=False)
        temp_file = "temp.mp3"
        tts.save(temp_file)

        # Modifying pitch for a deeper male voice using FFmpeg
        os.system(f"ffmpeg -i {temp_file} -filter:a \"asetrate=22050*0.9,atempo=0.9\" {audio_file} -y")
        os.remove(temp_file)  # Removing temporary file
    else:
        tts = gTTS(text=text, lang="en", slow=False)
        tts.save(audio_file)

    return audio_file

# Start command handler
async def start(update: Update, context: ContextTypes.DEFAULT_TYPE):
    welcome_text = """🎙 Welcome to the Voice Bot!  
I can convert your text into speech. Please select a voice:  
✅ Male  
✅ Female  

Reply with your choice."""

    # Keyboard options for easy selection
    keyboard = [["Male", "Female"]]
    reply_markup = ReplyKeyboardMarkup(keyboard, one_time_keyboard=True)

    await update.message.reply_text(welcome_text, reply_markup=reply_markup)

# Handle user voice preference selection
async def set_voice_preference(update: Update, context: ContextTypes.DEFAULT_TYPE):
    user_id = update.message.chat_id
    choice = update.message.text.lower()

    if choice in ["male", "female"]:
        user_voice_preferences[user_id] = choice
        await update.message.reply_text(f"✅ Voice set to {choice.capitalize()}! Now send me any text, and I'll convert it to speech.")
    else:
        await update.message.reply_text("⚠ Invalid choice! Please select 'Male' or 'Female'.")

# Handle text-to-speech conversion
async def speak_message(update: Update, context: ContextTypes.DEFAULT_TYPE):
    user_id = update.message.chat_id
    text = update.message.text

    # Get user's preferred voice, default to female
    gender = user_voice_preferences.get(user_id, "female")

    audio_file = text_to_speech(text, gender=gender)

    if os.path.exists(audio_file):
        with open(audio_file, "rb") as audio:
            await update.message.reply_voice(voice=audio)
    else:
        await update.message.reply_text("⚠ Error: Audio file not found!")

# Main function to start the bot
def main():
    app = Application.builder().token(TOKEN).build()

    app.add_handler(CommandHandler("start", start))
    app.add_handler(MessageHandler(filters.Regex("^(Male|Female)$"), set_voice_preference))
    app.add_handler(MessageHandler(filters.TEXT & ~filters.COMMAND, speak_message))

    print("🤖 Kaushik Bot is running...")
    app.run_polling()

if name == "__main__":
    main()


Cr - kauahik