// ignore: file_names
import 'package:test_flutter/TipoMoto.dart';

class Motor {
  int cv = 200;
  int cc = 200;
  int kilometraje = 0;
  bool inyeccion = false;
  TipoMoto tipoMoto = TipoMoto.MOTODEPORTIVA;

  Motor(TipoMoto tipoMoto) {
    if (tipoMoto == TipoMoto.MOTODEPORTIVA) {
      cv = 200;
      cc = 1000;
      kilometraje = 5;
      inyeccion = true;
    } else if (tipoMoto == TipoMoto.MOTOSCOOTER) {
      cv = 25;
      cc = 150;
      kilometraje = 15000;
      inyeccion = false;
    } else if (tipoMoto == TipoMoto.MOTOTOURING) {
      cv = 100;
      cc = 600;
      kilometraje = 100000;
      inyeccion = true;
    }
  }

/*
  set cvs(int cv) {
    this.cv = cv;
  }

  set ccs(int cc) {
    cc = cc;
  }

  set kilometrajes(int kilometraje) {
    kilometraje = kilometraje;
  }

  set inyeccions(bool inyeccion) {
    inyeccion = inyeccion;
  }*/

  @override
  String toString() {
    String s = "\n";
    s += "\t\t • Caballos: $cv\n";
    s += "\t\t • Cilindarada: $cc\n";
    s += "\t\t • Kilometraje: $kilometraje\n";
    if (inyeccion) {
      s += '\t\t • Inyección ✔';
    } else {
      s += '\t\t • Inyección X';
    }
    return s;
  }
}
