Kaushik Cracking:
import logging
import random
import requests
import asyncio
from telegram import Update
from telegram.ext import Application, CommandHandler, CallbackContext

# Use your bot token here
TOKEN = 'YOUR_BOT_TOKEN'
# Guerrilla Mail API base URL
GUERRILLA_API_BASE = 'https://api.guerrillamail.com/ajax.php'

# Store the temp email and OTP status in memory (for current session)
user_data = {}

# Generate a temporary email address using Guerrilla Mail
def generate_temp_mail():
    url = GUERRILLA_API_BASE
    params = {
        'f': 'get_email_address',  # Request to get a new temporary email address
    }
    try:
        response = requests.get(url, params=params)
        print(f"Guerrilla API Response Code: {response.status_code}")  # Log status code
        print(f"Guerrilla API Response Body: {response.text}")  # Log response body

        if response.status_code == 200:
            data = response.json()  # Parse JSON response
            temp_email = data.get('email_addr')
            return temp_email
        else:
            print(f"Unexpected response from Guerrilla Mail API: {response.status_code}")
            return None
    except requests.exceptions.RequestException as e:
        print(f"Error generating temp mail: {e}")
        return None

# Fetch OTP from the Guerrilla Mail inbox
def get_otp(temp_email):
    email_part = temp_email.split('@')[0]  # Extract the email part before '@'
    url = GUERRILLA_API_BASE
    params = {
        'f': 'check_mail',  # Request to check inbox
        'seq': '1',  # Starting mail sequence
        'email': temp_email,  # Pass the email to check its inbox
    }
    try:
        response = requests.get(url, params=params)
        print(f"Inbox API Response Code: {response.status_code}")  # Log status code
        print(f"Inbox API Response Body: {response.text}")  # Log response body

        if response.status_code == 200:
            mails = response.json().get('messages', [])
            if mails:
                for mail in mails:
                    if 'otp' in mail['subject'].lower() or 'otp' in mail['body'].lower():  # Check both subject and body
                        return mail['body']
        return None
    except requests.exceptions.RequestException as e:
        print(f"Error fetching OTP: {e}")
        return None

# Command handler for /start (Welcome message)
async def start(update: Update, context: CallbackContext) -> None:
    await update.message.reply_text('Welcome! Type /tempmail to get a temporary email address and OTP.')

# Command handler for /tempmail (Generates a temp email and fetches OTP)
async def tempmail(update: Update, context: CallbackContext) -> None:
    temp_mail = generate_temp_mail()
    if temp_mail:
        user_data[update.message.chat_id] = {'temp_email': temp_mail, 'otp': None}
        await update.message.reply_text(f'Your temporary email address is: {temp_mail}')

        # Wait for OTP (time delay for email to arrive)
        await update.message.reply_text("Please wait while I fetch OTP...")

        # Allow time for email to arrive
        for _ in range(10):  # Checking for OTP every 3 seconds for 30 seconds
            otp = get_otp(temp_mail)
            if otp:
                user_data[update.message.chat_id]['otp'] = otp
                await update.message.reply_text(f'OTP for your temporary email {temp_mail} is: {otp}')
                return
            await asyncio.sleep(3)  # Wait for 3 seconds before checking again

        await update.message.reply_text(f'No OTP received for email: {temp_mail}')
    else:
        await update.message.reply_text('Failed to generate temporary email. Please try again later.')

# Command handler for /refresh (Refreshes the OTP)
async def refresh(update: Update, context: CallbackContext) -> None:
    if update.message.chat_id in user_data and user_data[update.message.chat_id].get('temp_email'):
        temp_mail = user_data[update.message.chat_id]['temp_email']

        # Reset OTP and check inbox again
        user_data[update.message.chat_id]['otp'] = None
        await update.message.

reply_text(f"Refreshing OTP for email: {temp_mail}")

        # Try to fetch OTP again
        for _ in range(10):  # Checking for OTP every 3 seconds for 30 seconds
            otp = get_otp(temp_mail)
            if otp:
                user_data[update.message.chat_id]['otp'] = otp
                await update.message.reply_text(f'OTP for your temporary email {temp_mail} is: {otp}')
                return
            await asyncio.sleep(3)  # Wait for 3 seconds before checking again

        await update.message.reply_text(f'No OTP received for email: {temp_mail}')
    else:
        await update.message.reply_text('No temporary email found. Please run /tempmail first.')

# Main function to set up the bot
def main() -> None:
    # Set up logging
    logging.basicConfig(format='%(asctime)s - %(name)s - %(levelname)s - %(message)s',
                        level=logging.INFO)
    logger = logging.getLogger(__name__)

    # Create the Application instance
    application = Application.builder().token(TOKEN).build()

    # Register command handlers
    application.add_handler(CommandHandler("start", start))
    application.add_handler(CommandHandler("tempmail", tempmail))
    application.add_handler(CommandHandler("refresh", refresh))  # Add refresh command handler

    # Start the bot
    application.run_polling()

if name == '__main__':
    main()

Temp mail Python Script 

pip install python-telegram-bot requests
python temp.py

Cr - kaushik