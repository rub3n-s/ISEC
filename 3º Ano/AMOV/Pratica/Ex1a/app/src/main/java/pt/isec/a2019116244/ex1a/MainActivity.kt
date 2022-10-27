package pt.isec.a2019116244.ex1a

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.view.View
import android.widget.Button
import android.widget.TextView
import pt.isec.a2019116244.ex1a.databinding.ActivityMainBinding

class MainActivity : AppCompatActivity(), View.OnClickListener {
    private lateinit var binding : ActivityMainBinding
    private var num1 : Int = 0
    private var num2 : Int = 0
    private var finalResult : Int = 0
    private var operator : String? = null
    private var decimal : Boolean = false
    var decimalTemp : String? = null

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)

        binding.btn0.setOnClickListener(this)
        binding.btn1.setOnClickListener(this)
        binding.btn2.setOnClickListener(this)
        binding.btn3.setOnClickListener(this)
        binding.btn4.setOnClickListener(this)
        binding.btn5.setOnClickListener(this)
        binding.btn6.setOnClickListener(this)
        binding.btn7.setOnClickListener(this)
        binding.btn8.setOnClickListener(this)
        binding.btn9.setOnClickListener(this)

        binding.btnAC.setOnClickListener(this)
        binding.btnMaisMenos.setOnClickListener(this)
        binding.btnMul.setOnClickListener(this)
        binding.btnSub.setOnClickListener(this)
        binding.btnSum.setOnClickListener(this)

        binding.btnCalc.setOnClickListener(this)
    }

    override fun onClick(view: View?) {
        when ((view as? Button)?.text as String) {
            "*","+","-","/","+/-" -> {
                operator = (view as? Button)?.text.toString()
                decimal = false
            }
            "AC" -> clear()
            "=" -> calc()
            "." -> decimal = true
            else -> {
                binding.tv.text = (view as? Button)?.text
                if (decimal)
                    decimalTemp = "$num1." + (view as? Button)?.text.toString()
                if (operator == null)
                    num1 = Integer.parseInt((view as? Button)?.text.toString())
                else
                    num2 = Integer.valueOf((view as? Button)?.text.toString())
            }
        }
    }

    fun clear() {
        num1 = 0
        num2 = 0
        finalResult = 0
        operator = null
        decimal = false
        binding.tv.text = "0"
    }

    fun calc() {
        when (operator) {
            "*" -> finalResult = num1 * num2
            "+" -> finalResult = num1 + num2
            "-" -> finalResult = num1 - num2
            "/" -> finalResult = num1 / num2
            //"+/-" -> finalResult = num1 / num2
        }
        binding.tv.text = finalResult.toString()
    }
}