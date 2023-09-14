import 'package:flutter/material.dart';

void main() {
  runApp(MyApp());
}

class MyApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return const MaterialApp(
      title: 'No se muestra',
      home: MyHomePage(
        title: 'Ir rapido o no ir rapido',
      ),
    );
  }
}

class MyHomePage extends StatefulWidget {
  final String title;

  const MyHomePage({super.key, required this.title});

  @override
  // ignore: library_private_types_in_public_api
  _HomePageState createState() =>
      // ignore: no_logic_in_create_state
      _HomePageState();
}

// ignore: must_be_immutable
class _HomePageState extends State<MyHomePage> {
  int _counter = 0;

  void _incrementCounter() {
    setState(() {
      _counter++;
    });
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text(
          widget.title,
          textDirection: TextDirection.ltr,
        ),
      ),
      body: Center(
        child: Text(
          'Número de veces pulsaciones +: $_counter. ¡Ya queda menos!',
        ),
      ),
      floatingActionButton: FloatingActionButton(
        onPressed: _incrementCounter,
        tooltip: 'Increment',
        child: Icon(Icons.add),
      ),
    );
  }
}
