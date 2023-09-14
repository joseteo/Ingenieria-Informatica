// ignore_for_file: file_names

import 'dart:async';

class Reloj {
  int _horas = 1;
  int _minutos = 1;
  //taller_dart2
  int _segundo = 0;
  static int _totalRelojes = 0;

  Reloj(int hora, int minuto, int segundo) {
    _horas = hora;
    _minutos = minuto;
    _segundo = segundo;
    _totalRelojes++;
  }

  Reloj.Reloj() {
    _totalRelojes++;
  }

  int getHora() {
    return _horas;
  }

  int getMinutos() {
    return _minutos;
  }

  int _totalHoraEnMinutos() {
    return (_horas * 60 + _minutos);
  }

  int totalHoraEnMinutosP() {
    return _totalHoraEnMinutos();
  }

  //taller_dart2
  void addSegundo() {
    if (_segundo + 1 >= 60) {
      if (_minutos + 1 >= 60) {
        if (_horas + 1 >= 24)
          throw const FormatException("La formato de horas es invalido.");
        else {
          _horas++;
          _minutos = 0;
          _segundo = 0;
        }
      } else {
        _minutos++;
        _segundo = 0;
      }
    } else {
      _segundo++;
    }
  }

  Future<String> marcarSegundo() {
    return Future.delayed(const Duration(seconds: 1), () {
      addSegundo();
      return "Segundo pasado";
    });
  }

  Future<String> refreshToString(Reloj refReloj) async {
    print(await refReloj.marcarSegundo());
    _horas = refReloj._horas;
    _minutos = refReloj._minutos;
    _segundo = refReloj._segundo;
    return toString();
  }

  @override
  String toString() {
    return "Reloj{hora(s): $_horas, minuto(s): $_minutos, segundo(s): $_segundo, total de horas en minutos: ${totalHoraEnMinutosP()}\n";
  }
}
