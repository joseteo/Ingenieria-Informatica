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
  TipoMoto get tipoMoto => this._tipoMoto;

  set tipoMoto(TipoMoto value) => this._tipoMoto = value;

  get motor => this._motor;

  set motor(value) => this._motor = value;

  get chasis => this._chasis;

  set chasis(value) => this._chasis = value;

  get asiento => this._asiento;

  set asiento(value) => this._asiento = value;

  get trenRodaje => this._trenRodaje;

  set trenRodaje(value) => this._trenRodaje = value;

  get electronica => this._electronica;

  set electronica(value) => this._electronica = value;

  Moto(
    this._tipoMoto,
    this._motor,
    this._chasis,
    this._asiento,
    this._trenRodaje,
    this._electronica,
  );
}
