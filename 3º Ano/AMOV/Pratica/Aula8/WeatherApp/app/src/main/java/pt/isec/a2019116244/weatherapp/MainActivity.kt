package pt.isec.a2019116244.weatherapp

import android.os.Bundle
import android.util.Log
import com.google.android.material.snackbar.Snackbar
import androidx.appcompat.app.AppCompatActivity
import androidx.navigation.findNavController
import androidx.navigation.ui.AppBarConfiguration
import androidx.navigation.ui.navigateUp
import androidx.navigation.ui.setupActionBarWithNavController
import android.view.Menu
import android.view.MenuItem
import android.widget.Toast
import androidx.activity.viewModels
import androidx.lifecycle.LiveData
import androidx.lifecycle.MutableLiveData
import androidx.lifecycle.ViewModel
import pt.isec.a2019116244.weatherapp.databinding.ActivityMainBinding
import java.net.URL

// os dados desta classe serao mantidos durante todas as fases da app
class MyViewModel : ViewModel() {
    private val _webContent = MutableLiveData<String?>(null)
    val webContent : LiveData<String?>
        get() = _webContent

    fun getContent(strURL: String) {
        NetUtils.getDataAsync(strURL,_webContent)
    }
}

class MainActivity : AppCompatActivity() {
    companion object {
        private const val ISEC_URL = "https://www.isec.pt"
        private const val API_KEY = "a3501ab875c94db6bb6122511221711"
        private const val CITY = "Coimbra"
        private const val WEATHER_URL = "https://api.weatherapi.com/v1/forecast.json?key=$API_KEY&q=$CITY&days=5&aqi=no&alerts=no"
    }

    private val viewModel: MyViewModel by viewModels()

    private lateinit var appBarConfiguration: AppBarConfiguration
    private lateinit var binding: ActivityMainBinding

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)

        setSupportActionBar(binding.toolbar)

        val navController = findNavController(R.id.nav_host_fragment_content_main)
        appBarConfiguration = AppBarConfiguration(navController.graph)
        setupActionBarWithNavController(navController, appBarConfiguration)

        binding.fab.setOnClickListener { view ->
            /* Snackbar.make(view, "Replace with your own action", Snackbar.LENGTH_LONG)
                .setAction("Action", null).show() */
            //viewModel.getContent(ISEC_URL) // obter os dados
            viewModel.getContent(WEATHER_URL)
            viewModel.webContent.observe(this) {    // visualizar os dados
                print(it)
            }
        }

        val netState1 = NetUtils.verifyNetworkState(this)
        val netState2 = NetUtils.verifyNetworkStateV2(this)
        val netState3 = NetUtils.verifyNetworkStateV3(this)

        Log.i("Mainactivity: ","ns1 = $netState1; ns2 = $netState2; ns3 = $netState3")
        if (!netState1 && !netState2 && !netState3) {
            Toast.makeText(this,"No network available", Toast.LENGTH_LONG).show()
            finish()
            return
        }
    }

    override fun onCreateOptionsMenu(menu: Menu): Boolean {
        // Inflate the menu; this adds items to the action bar if it is present.
        menuInflater.inflate(R.menu.menu_main, menu)
        return true
    }

    override fun onOptionsItemSelected(item: MenuItem): Boolean {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        return when (item.itemId) {
            R.id.action_settings -> true
            else -> super.onOptionsItemSelected(item)
        }
    }

    override fun onSupportNavigateUp(): Boolean {
        val navController = findNavController(R.id.nav_host_fragment_content_main)
        return navController.navigateUp(appBarConfiguration)
                || super.onSupportNavigateUp()
    }
}