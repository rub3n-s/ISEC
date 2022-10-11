package pt.isec.a2019116244.aula2_ciclovida

import android.app.Activity
import android.os.Bundle
import android.util.Log

// maximo de 23 caracteres para a TAG
const val TAG = "aula2_ciclovida"

// em Kotlin temos de chamar o construtor diretamente na classe Base
class MyActivity : Activity() {
    var conta = 0

    val app : MyApp by lazy { application as MyApp }

    fun Logi(tag : String, msg : String) {
        //Log.i(tag, "$msg ${app.my_value}")
        Log.i(tag, "$msg ${MyObject.my_value}")
    }

    // este metodo e chamado ao criar
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.my_activity)
        conta++
        Logi(TAG, "onCreate: $conta")
    }

    override fun onStart() {
        super.onStart()
        conta++
        Logi(TAG,"onStart: $conta");
    }

    override fun onResume() {
        super.onResume()
        conta++
        Logi(TAG,"onResume: $conta");
    }

    override fun onPause() {
        super.onPause()
        conta++
        Logi(TAG,"onPause: $conta");
    }

    override fun onStop() {
        super.onStop()
        conta++
        Logi(TAG,"onStop: $conta");
    }

    override fun onDestroy() {
        super.onDestroy()
        conta++
        Logi(TAG,"onDestroy: $conta");
    }

    override fun onSaveInstanceState(outState: Bundle) {
        super.onSaveInstanceState(outState)
        conta++
        Logi(TAG, "onSaveInstanceState: $conta")
        outState.putInt("valor",conta)
    }

    override fun onRestoreInstanceState(savedInstanceState: Bundle) {
        super.onRestoreInstanceState(savedInstanceState)
        conta = savedInstanceState.getInt("valor")
        Logi(TAG, "onRestoreInstanceState: $conta")
    }
}