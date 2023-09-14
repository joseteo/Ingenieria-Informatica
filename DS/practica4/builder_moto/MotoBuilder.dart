import 'Electronica.dart';
import 'Motor.dart';
import 'Moto.dart';
import 'TrenRodaje.dart';
import 'TipoMoto.dart';
import 'Asiento.dart';
import 'Chasis.dart';
import 'Builder.dart';

class MotoBuilder implements Builder {
  TipoMoto tipo;
  Chasis chasis;
  Asiento asiento;
  Motor motor;
  TrenRodaje trenRodaje;
  Electronica electronica;

  MotoBuilder(
    this.tipo,
    this.chasis,
    this.asiento,
    this.motor,
    this.trenRodaje,
    this.electronica,
  );

  @override
  void setMotoTipo(TipoMoto tipo) {
    this.tipo = tipo;
  }

  @override
  void setChasis(Chasis chasis) {
    this.chasis = chasis;
  }

  @override
  void setAsientos(Asiento asiento) {
    this.asiento = asiento;
  }

  @override
  void setMotor(Motor motor) {
    this.motor = motor;
  }

  @override
  void setTrenRodaje(TrenRodaje trenRodaje) {
    this.trenRodaje = trenRodaje;
  }

  @override
  void setElectronica(Electronica electronica) {
    this.electronica = electronica;
  }

  Moto entregaMoto() {
    return Moto(tipo, motor, chasis, asiento, trenRodaje, electronica);
  }
}
