/*import 'package:flutter/material.dart';
import 'paginaPremio.dart';

void main() {
  runApp(MaterialApp(
    title: 'Demo de premio',
    home: PaginaInicio(),
  ));
}

class PaginaInicio extends StatefulWidget {
  @override
  _PaginaInicioState createState() => _PaginaInicioState();
}

class _PaginaInicioState extends State<PaginaInicio> {
  int _contador = 0;

  void _incrementarContador() {
    setState(() {
      _contador++;
    });

    if (_contador == 10) {
      Navigator.push(
        context,
        MaterialPageRoute(builder: (context) => PaginaPremio()),
      );
    }
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('Página de inicio'),
      ),
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: <Widget>[
            Text(
              'Pulsa el botón 10 veces para obtener un premio:',
            ),
            Text(
              '$_contador',
              style: Theme.of(context).textTheme.headline4,
            ),
          ],
        ),
      ),
      floatingActionButton: FloatingActionButton(
        onPressed: _incrementarContador,
        tooltip: 'Incrementar',
        child: Icon(Icons.add),
      ),
    );
  }
}
*/

//taller flutter 2
import 'package:flutter/material.dart';
import 'paginaPremio.dart';
import 'paginaDonacion.dart' as donacion;

void main() {
  runApp(MaterialApp(
    title: 'Demo de premio',
    initialRoute: '/',
    routes: {
      '/': (context) => PaginaInicio(),
      '/premio': (context) => PaginaPremio(),
      '/donacion': (context) => donacion.PaginaDonacion(),
    },
  ));
}

class PaginaInicio extends StatefulWidget {
  @override
  _PaginaInicioState createState() => _PaginaInicioState();
}

class _PaginaInicioState extends State<PaginaInicio> {
  int _contador = 0;

  void _incrementarContador() {
    setState(() {
      _contador++;
    });

    if (_contador == 10) {
      _resetContador();
      Navigator.pushNamed(context, '/premio');
    }
  }

  void _resetContador() {
    setState(() {
      _contador = 0;
    });
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('Página de inicio'),
      ),
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: <Widget>[
            Text(
              'Pulsa el botón 10 veces para obtener un premio:',
            ),
            Text(
              '$_contador',
              style: Theme.of(context).textTheme.headline4,
            ),
          ],
        ),
      ),
      floatingActionButton: FloatingActionButton(
        onPressed: _incrementarContador,
        tooltip: 'Incrementar',
        child: Icon(Icons.add),
      ),
    );
  }
}
