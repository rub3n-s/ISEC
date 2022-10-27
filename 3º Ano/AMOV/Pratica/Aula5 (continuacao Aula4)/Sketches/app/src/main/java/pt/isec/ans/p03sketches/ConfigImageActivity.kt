package pt.isec.ans.p03sketches

import android.content.Context
import android.content.Intent
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import pt.isec.ans.p03sketches.databinding.ActivityConfigImageBinding

class ConfigImageActivity : AppCompatActivity() {
    companion object {
        private const val GALLERY = 1
        private const val CAMERA = 2

        private const val MODE_KEY = "mode"

        fun getGalleryIntent(context: Context) : Intent {
            val intent = Intent(context,ConfigImageActivity::class.java)
            intent.putExtra(MODE_KEY,GALLERY)
            return intent
        }

        fun getCameraIntent(context: Context) : Intent {
            val intent = Intent(context,ConfigImageActivity::class.java)
            intent.putExtra(MODE_KEY, CAMERA)
            return intent
        }
    }

    private var mode = GALLERY
    private lateinit var binding : ActivityConfigImageBinding

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        binding = ActivityConfigImageBinding.inflate(layoutInflater)
        setContentView(binding.root)

        mode = intent.getIntExtra(MODE_KEY, GALLERY)
        when (mode) {
            GALLERY -> binding.btnImage.apply {
                text = getString(R.string.btn_choose_image)
                setOnClickListener() { chooseImage() }
            }
            CAMERA -> binding.btnImage.apply {
                text = getString(R.string.btn_take_photo)
                setOnClickListener() { takePhoto() }
            }
            else -> finish()
        }
        supportActionBar?.setDisplayHomeAsUpEnabled(true)
    }

    private fun chooseImage() { }

    private fun takePhoto() { }
}