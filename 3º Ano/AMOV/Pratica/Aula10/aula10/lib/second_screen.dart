import 'package:flutter/material.dart';

class SecondScreen extends StatefulWidget {
  const SecondScreen({Key? key}) : super(key: key);

  static const String routName = '/SecondScreen';

  @override
  State<SecondScreen> createState() => _SecondScreenState();
}

class _SecondScreenState extends State<SecondScreen> {
  late final int _counter = ModalRoute.of(context)!.settings.arguments as int;

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
          backgroundColor: Colors.deepPurple,
          title: const Text(
              "Second Screen",
              style: TextStyle(
                  color: Colors.indigo
              )
          ),
      ),
      body: Center(
        child : Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: [
            SizedBox(height:200 ,child: Image.asset('images/user_img1.png')),
            SizedBox(height: 50, child: Image.network('https://www.isec.pt/assets_isec/logo-isec-transparente.png')),
            Hero(
                tag: 'AmovTag1',
                child: Text('Valor = $_counter')
            ),
            ElevatedButton(
                onPressed: () => Navigator.of(context).pop(_counter * 2),
                child: const Text('Return')
            )
          ],
        )
      ),
    );
  }
}
