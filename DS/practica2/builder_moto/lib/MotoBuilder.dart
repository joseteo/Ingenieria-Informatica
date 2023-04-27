import 'Electronica.dart';
import 'Motor.dart';
import 'Moto.dart';
import 'TrenRodaje.dart';
import 'TipoMoto.dart';
import 'Asiento.dart';
import 'Chasis.dart';
import 'Builder.dart';
import 'TipoFrenos.dart';
import 'TipoSuspension.dart';

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
  void setMotoTipo({TipoMoto tipo = TipoMoto.MOTODEPORTIVA}) {
    this.tipo = tipo;
  }

  @override
  void setChasis({Chasis chasis = Chasis.MONOCASCO}) {
    this.chasis = chasis;
  }

  @override
  void setAsientos({Asiento asiento = Asiento.ASIENTOBLANCO}) {
    this.asiento = asiento;
  }

  @override
  void setMotor(
      {int cv = 200,
      int cc = 200,
      int kilometraje = 0,
      bool inyeccion = true}) {
    motor.cv = cv;
    motor.cc = cc;
    motor.kilometraje = kilometraje;
    motor.inyeccion = inyeccion;
  }

  @override
  void setTrenRodaje(
      {int pulgadaRueda = 14,
      TipoFrenos tipoFrenos = TipoFrenos.DISCO,
      TipoSuspension tipoSuspension = TipoSuspension.MEDIA}) {
    trenRodaje.pulgadaRueda = pulgadaRueda;
    trenRodaje.tipoFrenos = tipoFrenos;
    trenRodaje.tipoSuspension = tipoSuspension;
  }

  @override
  void setElectronica(
      {bool abs = false,
      bool controlCrucero = false,
      bool controlTraccion = false,
      bool repartoFrenada = false}) {
    electronica.abs = abs;
    electronica.controlCrucero = controlCrucero;
    electronica.controlTraccion = controlTraccion;
    electronica.repartoFrenada = repartoFrenada;
  }

  Moto entregaMoto() {
    return Moto(tipo, motor, chasis, asiento, trenRodaje, electronica);
  }
}
