##Submit auto-renewable subscriptions to iTunes Connect
It's not possible to use Apple's Application Uploader to add subscriptions to Connect, so you manually have to add auto-renewable subscriptions to Connect.

To get the information you need to enter in Connect go to:


```
HTML: curl 'https://api.schedjoules.com/apps/renewable_subscriptions.html' -v -H 'Authorization: Token token="{YOUR_API_KEY}"'

JSON: curl 'https://api.schedjoules.com/apps/renewable_subscriptions' -v -H 'Authorization: Token token="{YOUR_API_KEY}"'
```

**Prepare your app for auto-renewable subscriptions:**
* Go to iTunes Connect
* Select the app you want to add subscriptions to
* Make sure you have a privacy policy in place and add the link to it. You can use ours as an example https://www.schedjoules.com/privacy-policy/
* Press 'Features' in top bar. You are now on the In-App Purchases tab
* Press 'View Shared Secret' and send that secret to us. We'll use it to validate the purchase date and expiration date of the subscriptions

**Add auto-renewable subscription to Connect:**
* Press '+' to add an IAP
* Select 'Automatically Renewable Subscriptions’
* Enter the information you find on https://api.schedjoules.com/apps/renewable_subscriptions.html.

NOTES:
* The identifier can't be changed in Connect, so if you make an error here, let us know so we can update our side.
* You can find the alternate pricing tiers at the bottom of the Price Tier dropdown.
* You only need to add the languages your app is targeted to

##Launch auto-renewable subscriptions in the Store
Your application description needs to meet the terms and conditions for auto-renewing subscriptions, as specified in Schedule 2, Section 3.8(b). Meeting the terms of this agreement is required by the App Store Review Guidelines.

Specifically, your Application Description has to include:

1. the length of the subscription
2. the price of the subscription
3. links to the privacy policy and terms of use

**Add the following text at the end of your Application Description**

*Access to Calendar Store for 1 year*<br/>
*With a yearly subscription you get full and ongoing access to the Calendar Store including (live) updates in your calendar. A subscription always starts with a one-month free trial, so you can try before you buy. 1 year subscriptions for the Calendar Store start at $0.99. Payment will be charged to your iTunes Account at confirmation of purchase and after the 1 month free trial. Subscriptions automatically renew unless auto-renew is turned off at least 24-hours before the end of the current period. Your account will be charged for renewal within 24-hours prior to the end of the current 1 year period. You can turn off auto-renew at any time from your iTunes account settings. Cancellation of the current active subscription period is not allowed.*

*Find the full terms and conditions, and our privacy policy, at [url] and [url] respectively.*

NOTE: Please be sure to add this text to all App Localizations by selecting each specific localization and making appropriate changes.

**Add text to Notes field for Apple Editors**

Click 'Prepare for Submission' and add the following text to the Notes field under 'App Review Information' to request Apple to disable the "Share Your Information" dialog" in the subscription purchase flow:

*I hereby want to request to disable the "Share Your Information" dialog for our application ID [NUMBER]. In your documentation you also state that there's an option for Auto Renewing subscriptions to "Offer a marketing opt-in incentived" - yes/no. This setting controls whether the user will be provided a bonus free period for sharing their information. This option is not available however.*




