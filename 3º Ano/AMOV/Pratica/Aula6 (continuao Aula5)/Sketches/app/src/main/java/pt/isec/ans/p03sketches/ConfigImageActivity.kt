package pt.isec.ans.p03sketches

import android.content.Context
import android.content.Intent
import android.net.Uri
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.util.Log
import android.view.Menu
import android.view.MenuItem
import androidx.activity.result.contract.ActivityResultContracts
import androidx.core.content.FileProvider
import androidx.core.content.res.ResourcesCompat
import com.google.android.material.snackbar.Snackbar
import pt.isec.ans.p03sketches.databinding.ActivityConfigImageBinding
import java.io.File
import java.io.FileOutputStream

class ConfigImageActivity : AppCompatActivity() {
    companion object {
        private const val PERMISSION_REQUEST_CODE = 10
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

    // OPCAO 1 - controlar as permissoes com Request Code
    private var permissionsGranted = false
        set(value) {
            field = value
            binding.btnImage.isEnabled = value
        }

    private var imagePath : String? = null

    // OPCAO 2 - controla permissoes com contratos
    val requestPermissionsLauncher = registerForActivityResult(
        ActivityResultContracts.RequestMultiplePermissions()
    ) { grantResults -> // Map<String,Boolean>
        permissionsGranted = grantResults.values.all { it } // se todos forem true (it)
    }

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        binding = ActivityConfigImageBinding.inflate(layoutInflater)
        setContentView(binding.root)

        supportActionBar?.setDisplayHomeAsUpEnabled(true)   // btn voltar p/ HomePage

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

        verifyPermissions()
        updatePreview()
    }

    private fun verifyPermissions() {
        // OPCAO 1 - Permissoes com Request Code
        /*if (ContextCompat.checkSelfPermission(
                this,
                android.Manifest.permission.READ_EXTERNAL_STORAGE
            ) != PackageManager.PERMISSION_GRANTED ||
            ContextCompat.checkSelfPermission(
                this,
                android.Manifest.permission.WRITE_EXTERNAL_STORAGE
            ) != PackageManager.PERMISSION_GRANTED) {
            permissionsGranted = false
            ActivityCompat.requestPermissions(this,
                arrayOf(
                    android.Manifest.permission.READ_EXTERNAL_STORAGE,
                    android.Manifest.permission.WRITE_EXTERNAL_STORAGE
                ),
                PERMISSION_REQUEST_CODE
            )
        }
        else
            permissionsGranted = true */

        // OPCAO 2 - Com Contratos
        requestPermissionsLauncher.launch(
            arrayOf(
                android.Manifest.permission.WRITE_EXTERNAL_STORAGE,
                android.Manifest.permission.READ_EXTERNAL_STORAGE
            )
        )
    }

    // OPCAO 1 - Permissoes com Request Code
    /*override fun onRequestPermissionsResult(
        requestCode: Int,
        permissions: Array<out String>, //  array de permissoes
        grantResults: IntArray          // granted/denied
    ) {
        if (requestCode == PERMISSION_REQUEST_CODE) {
            // verificar se tens as permissoes
            permissionsGranted = grantResults.all { it == PackageManager.PERMISSION_GRANTED }
            return
        }
        super.onRequestPermissionsResult(requestCode, permissions, grantResults)
    }*/

    private fun chooseImage() {
        val intent = Intent(Intent.ACTION_PICK)
        intent.setType("image/*")
        startActivityForResult(intent,10)
    }

    override fun onActivityResult(requestCode: Int, resultCode: Int, data: Intent?) {
        if (requestCode == 10 && resultCode == RESULT_OK && data != null) {
            data.data?.let {
                imagePath = createFileFromUri(this,it)
                updatePreview()
            }
            return
        }
        super.onActivityResult(requestCode, resultCode, data)
    }

    fun updatePreview() {   // sempre que atualizarmos a imagem chama este metodo
        if (imagePath != null)
            setPic(binding.frPreview, imagePath!!)
        else
            binding.frPreview.background = ResourcesCompat.getDrawable(
                resources,
                android.R.drawable.ic_menu_report_image,
                null
            )
    }

    // =========== TIRAR FOTOGRAFIA
    // criar contrato para tirar fotografia
    var startActivityForTakePhotoResult = registerForActivityResult(
        ActivityResultContracts.TakePicture()
    ) { success ->
        if (success) {
            if (!success)
                imagePath = null
            updatePreview()
        }
    }

    private fun takePhoto() {
        imagePath = getTempFilename(this)
        startActivityForTakePhotoResult.launch(
            FileProvider.getUriForFile(this,
                "pt.isec.amov.sketches.android.fileprovider",
                File(imagePath)
            )
        )
    }

    // =========== ULTIMO PASSO
    // Passar a imagem para o DrawingArea
    override fun onCreateOptionsMenu(menu: Menu?): Boolean {
        menuInflater.inflate(R.menu.menu_create,menu)
        return true
    }

    override fun onOptionsItemSelected(item: MenuItem): Boolean {
        if (item.itemId == R.id.mnCreate && imagePath != null) {
            if (binding.edTitle.text.trim().isBlank()) {
                Snackbar.make(binding.edTitle,
                    R.string.msg_empty_title, Snackbar.LENGTH_LONG)
                    .show()
                binding.edTitle.requestFocus()
                return true
            }

            val intent = DrawingAreaActivity.getIntent(
                this,
                binding.edTitle.text.trim().toString(),
                imagePath
            )

            startActivity(intent)
            finish()
            return true
        }
        return super.onOptionsItemSelected(item)
    }
}