package pt.isec.amov.firebase

import android.util.Log
import com.google.firebase.messaging.FirebaseMessagingService
import com.google.firebase.messaging.RemoteMessage
import java.lang.Exception

class MyFirebaseMessagingService : FirebaseMessagingService() {
    companion object {
        const val TAG = "MyFMS"
    }
    override fun onMessageReceived(rMsg: RemoteMessage) {
        super.onMessageReceived(rMsg)
        if (rMsg.data.isNotEmpty()) {
            Log.i(TAG, "onMessageReceived - Data: " +
                    rMsg.data.toString())
        }
        rMsg.notification?.run {
            Log.i(TAG, String.format(
                "onMessageReceived - Notification: %s %s %s %s %s",
                title, body, icon, imageUrl, channelId)
            )
        }
    }

    override fun onNewToken(token: String) {
        super.onNewToken(token)
    }

    override fun onDeletedMessages() {
        super.onDeletedMessages()
    }

    override fun onSendError(msgId: String, exception: Exception) {
        super.onSendError(msgId, exception)
    }
}