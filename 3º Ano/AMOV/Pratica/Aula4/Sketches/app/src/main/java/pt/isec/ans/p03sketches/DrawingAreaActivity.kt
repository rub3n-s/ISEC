package pt.isec.ans.p03sketches

import android.graphics.Color
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import pt.isec.ans.p03sketches.databinding.ActivityDrawingAreaBinding

class DrawingAreaActivity : AppCompatActivity() {
    lateinit var binding: ActivityDrawingAreaBinding
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        binding = ActivityDrawingAreaBinding.inflate(layoutInflater)
        setContentView(binding.root)

        supportActionBar?.setDisplayHomeAsUpEnabled(true)

        val title = intent.getStringExtra("title") ?: getString(R.string.str_no_name)
        supportActionBar?.title = getString(R.string.sketches_title) + ": " + title

        val r = intent.getIntExtra("red",255)
        val g = intent.getIntExtra("green",255)
        val b = intent.getIntExtra("blue",255)

        binding.frDrawingArea.setBackgroundColor(Color.rgb(r,g,b))

    }
}