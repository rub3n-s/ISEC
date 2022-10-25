package pt.isec.a2019116244.layouts

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.view.View
import android.widget.Button
import android.widget.TextView
import pt.isec.a2019116244.layouts.databinding.ActivityMainBinding

class MainActivity : AppCompatActivity(), View.OnClickListener {
    //var tvTexto : TextView? = null
    //lateinit var tvTexto : TextView

    private lateinit var binding : ActivityMainBinding

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        binding = ActivityMainBinding.inflate(layoutInflater)
        //setContentView(R.layout.activity_main)
        setContentView(binding.root)

        //var tvTexto : TextView = findViewById(R.id.tvTexto)
        binding.tvTexto.text="DEIS-AMOV"
        xpto()

        binding.btOpcao1.setOnClickListener(this)
        binding.btOpcao2.setOnClickListener(this)
    }

    fun xpto() {
        binding.tvTexto.text="aaaaaaa"
    }

    override fun onClick(view: View?) {
        //binding.tvTexto.text="Opcao 1"
        binding.tvTexto.text = (view as? Button)?.text
    }
}