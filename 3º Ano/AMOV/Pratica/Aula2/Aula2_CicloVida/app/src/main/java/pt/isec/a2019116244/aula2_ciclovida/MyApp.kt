package pt.isec.a2019116244.aula2_ciclovida

import android.app.Application
import android.content.res.Configuration
import android.util.Log

class MyApp : Application() {
    private var _my_value = 0
    val my_value : Int
        get() = ++_my_value

    override fun onCreate() {
        super.onCreate()
        Log.i(TAG, "MyApp.onCreate: $my_value")
    }

    override fun onLowMemory() {
        super.onLowMemory()
    }

    override fun onTrimMemory(level: Int) {
        super.onTrimMemory(level)
    }

    override fun onConfigurationChanged(newConfig: Configuration) {
        super.onConfigurationChanged(newConfig)
        Log.i(TAG, "onConfigurationChanged: $newConfig")
    }

    override fun onTerminate() {
        super.onTerminate()
    }
}