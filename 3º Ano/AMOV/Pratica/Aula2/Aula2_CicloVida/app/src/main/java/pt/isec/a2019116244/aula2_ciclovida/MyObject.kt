package pt.isec.a2019116244.aula2_ciclovida

object MyObject {
    private var _my_value = 1000

    init {
        _my_value = 123456
    }

    val my_value : Int
        get() = --_my_value
}