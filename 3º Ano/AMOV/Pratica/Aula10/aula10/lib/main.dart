import 'dart:math';

import 'package:aula10/cat_fact_screens.dart';
import 'package:aula10/second_screen.dart';
import 'package:flutter/material.dart';
import 'package:shared_preferences/shared_preferences.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  // This widget is the root of your application.
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Flutter Demo',
      theme: ThemeData(
        primarySwatch: Colors.deepPurple,
      ),
      //home: const MyHomePage(title: 'First Flutter App'),
      initialRoute: MyHomePage.routeName,
      routes: {
        MyHomePage.routeName : (context) => const MyHomePage(title: 'First Flutter App'),
        SecondScreen.routName : (context) => const SecondScreen(),
        CatFactsScreen.routeName : (context) => const CatFactsScreen()
      },
      debugShowCheckedModeBanner: false,  // remove o simbolo debug que aparece no canto do ecra
    );
  }
}

class MyHomePage extends StatefulWidget {
  const MyHomePage({super.key, required this.title});

  static const String routeName = '/';

  final String title;

  @override
  State<MyHomePage> createState() => _MyHomePageState();
}

class _MyHomePageState extends State<MyHomePage> {
  int _counter = 0;
  Color? _backgroundColor;

  int _inc=1;
  final TextEditingController _tec = TextEditingController();

  @override
  void initState() {
    // TODO: implement initState
    super.initState();
    debugPrint('initState');
    _tec.addListener(() {

    });
    initInc();
    //_tec.text = "asdasda";
  }

  @override
  void dispose() {
    _tec.dispose();
    super.dispose();
    debugPrint('dispose');
  }

  @override
  void didChangeDependencies() {
    // TODO: implement didChangeDependencies
    super.didChangeDependencies();
    debugPrint('changeDispose');
  }

  @override
  void didUpdateWidget(covariant MyHomePage oldWidget) {
    // TODO: implement didUpdateWidget
    super.didUpdateWidget(oldWidget);
    debugPrint('updateWidget');
  }

  void _incrementCounter() async {
    setState(() {
      // This call to setState tells the Flutter framework that something has
      // changed in this State, which causes it to rerun the build method below
      // so that the display can reflect the updated values. If we changed
      // _counter without calling setState(), then the build method would not be
      // called again, and so nothing would appear to happen.
      _counter += _inc;
      _updateBackgroundColor();
    });

    if (_counter == 5) {
      var result = await Navigator.pushNamed(context, SecondScreen.routName,arguments: _counter);

      if (result is int) {
        _counter = result;
        setState(() { });
      }
    }
  }

  void _decrementCounter() {
    setState(() {
      // This call to setState tells the Flutter framework that something has
      // changed in this State, which causes it to rerun the build method below
      // so that the display can reflect the updated values. If we changed
      // _counter without calling setState(), then the build method would not be
      // called again, and so nothing would appear to happen.
      _counter--;
      _updateBackgroundColor();
    });
  }

  void _updateBackgroundColor() {
      _backgroundColor = Color.fromRGBO(Random().nextInt(255), Random().nextInt(255), Random().nextInt(255), 1.0);
  }

  Future<void> initInc() async {
    var prefs = await SharedPreferences.getInstance();
    setState(() {_inc = prefs.getInt('increment') ?? 1;});
  }

  /*void changeInc(int inc) {
    setState(() {
      _inc = inc;
    });
  } */

  Future<void> changeInc(int inc) async {
    setState(() {_inc = inc;});
    var prefs = await SharedPreferences.getInstance();
    await prefs.setInt('increment', _inc);
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: _backgroundColor,
      appBar: AppBar(
        title: Text(widget.title),
      ),
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: <Widget>[
            /*if (_counter > 10) const FlutterLogo(
              size: 200
            ),*/
            FlutterLogo(
              size: _counter > 10 ? 200 : 0,
            ),
            const Text(
              'You have pushed the button this many times:',
            ),
            Row(
              mainAxisAlignment: MainAxisAlignment.center,
              children: [
                const Text('>>>>>>>>>'),
                Text(
                  '$_counter',
                  style: Theme.of(context).textTheme.headline4,
                ),
                const Text('<<<<<<<<<')
              ],
            ),
            /*SizedBox(
                height: 150,
                width: 150,
                child: TextField(
                  decoration: const InputDecoration(
                    labelText: 'Increment:',
                    hintText: 'Value to increment',
                  ),
                  onChanged: (value) => changeInc(int.tryParse(value) ?? 1),
                )
            ),*/
            SizedBox(
              width: 200,
              child: TextFormField(
                decoration: const InputDecoration(
                  labelText: 'Increment:',
                  hintText: 'Value to increment',
                  border: OutlineInputBorder(),
                ),
                controller: _tec,
                //key: Key("$_inc"),
                //initialValue: "$_inc",
                onChanged: (value) => changeInc(int.tryParse(value) ?? 1),
              ),
            ),
            Padding(
              padding: const EdgeInsets.all(8.0),
              child: ElevatedButton(
                  onPressed: () => { setState(() { _counter = 0; })}, // inline function
                  child: const Text('Reset')
              ),
            ),
            Hero(
              tag: 'AmovTag1',
              child: ElevatedButton(
                  onPressed: () => Navigator.push(
                      context,
                      MaterialPageRoute(
                          builder: (context) => SecondScreen(),
                          settings: RouteSettings(arguments: _counter),

                      )
                  ),
                  child: const Text('Second Screen (explicit)')
              ),
            ),
            Hero(
              tag: 'AmovTag2',
              child: ElevatedButton(
                  onPressed: () => Navigator.pushNamed(
                      context,
                      SecondScreen.routName,
                      arguments: _counter
                  ),
                  child: const Text('Second Screen (routes)')
              ),
            ),
            ElevatedButton(
                onPressed: () => Navigator.pushNamed(
                    context,
                    CatFactsScreen.routeName
                ),
                child: const Text('Cat Facts Screen')
            )
          ],
        ),
      ),
      floatingActionButton: Row(
        mainAxisAlignment: MainAxisAlignment.spaceBetween,
        children: [
          Padding(
            padding: const EdgeInsets.fromLTRB(30, 0, 0, 0),
            child: FloatingActionButton(
              heroTag: 'AmovTagFB1',
              onPressed: _decrementCounter,
              tooltip: 'Decrement',
              child: const Icon(Icons.remove),
            ),
          ),
          FloatingActionButton(
            heroTag: 'AmovTagFB2',
            onPressed: _incrementCounter,
            tooltip: 'Increment',
            child: const Icon(Icons.add),
          )
        ],
      )
    );
  }
}
