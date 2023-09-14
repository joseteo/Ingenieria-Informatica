/*import 'package:flutter/material.dart';

class PaginaPremio extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('¡Felicidades!'),
      ),
      body: Center(
        child: Text(
          'Has ganado un premio',
          style: TextStyle(fontSize: 24),
        ),
      ),
    );
  }
}
*/

//taller flutter 2
import 'package:flutter/material.dart';

class PaginaPremio extends StatefulWidget {
  @override
  _PaginaPremioEstado createState() => _PaginaPremioEstado();
}

class _PaginaPremioEstado extends State<PaginaPremio> {
  bool _isMounted = false;
  int _donaciones = 0;

  @override
  void initState() {
    super.initState();
    _isMounted = true;
  }

  @override
  void dispose() {
    _isMounted = false;
    super.dispose();
  }

  void _donarPremio() async {
    await Future.delayed(Duration(seconds: 1));

    if (_isMounted) {
      setState(() {
        _donaciones++;
      });
    }
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('Página de premio'),
      ),
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: [
            Text(
              'Has donado $_donaciones premios',
              style: TextStyle(fontSize: 24),
            ),
            ElevatedButton(
              onPressed: () {
                Navigator.push(
                  context,
                  MaterialPageRoute(
                    builder: (context) => PaginaDonacion(
                      totalDonaciones: _donaciones,
                      onDonar: _donarPremio,
                    ),
                  ),
                ).then((value) {
                  if (_isMounted) {
                    setState(() {});
                  }
                });
              },
              child: Text('Donar premio'),
            ),
          ],
        ),
      ),
    );
  }
}

class PaginaDonacion extends StatelessWidget {
  final int totalDonaciones;
  final VoidCallback onDonar;

  const PaginaDonacion({
    Key? key,
    required this.totalDonaciones,
    required this.onDonar,
  }) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('Donaciones'),
      ),
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: <Widget>[
            Text(
              'Total de donaciones recibidas: $totalDonaciones',
              style: TextStyle(fontSize: 24),
            ),
            ElevatedButton(
              onPressed: () {
                onDonar();
              },
              child: Text('Recibir donación'),
            ),
          ],
        ),
      ),
    );
  }
}
