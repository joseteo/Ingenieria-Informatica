import 'Electronica.dart';
import 'Motor.dart';
import 'TrenRodaje.dart';
import 'TipoMoto.dart';
import 'Asiento.dart';
import 'Chasis.dart';

class Moto {
  TipoMoto _tipoMoto;
  Motor _motor;
  Chasis _chasis;
  Asiento _asiento;
  TrenRodaje _trenRodaje;
  Electronica _electronica;


  Moto(
    this._tipoMoto,
    this._motor,
    this._chasis,
    this._asiento,
    this._trenRodaje,
    this._electronica,
  );
}