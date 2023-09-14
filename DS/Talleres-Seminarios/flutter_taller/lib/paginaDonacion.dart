import 'package:flutter/material.dart';

class PaginaDonacion extends StatefulWidget {
  @override
  _PaginaDonacionState createState() => _PaginaDonacionState();
}

class _PaginaDonacionState extends State<PaginaDonacion> {
  int _totalDonaciones = 0;

  void _addDonacion() {
    setState(() {
      _totalDonaciones++;
    });
  }

  @override
  void initState() {
    super.initState();
    _addDonacion();
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('Página de donación'),
      ),
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: <Widget>[
            Text(
              'Total de donaciones realizadas: $_totalDonaciones',
              style: TextStyle(fontSize: 24),
            ),
            ElevatedButton(
              onPressed: () {
                Navigator.pop(context);
              },
              child: Icon(Icons.home),
            ),
          ],
        ),
      ),
    );
  }
}
