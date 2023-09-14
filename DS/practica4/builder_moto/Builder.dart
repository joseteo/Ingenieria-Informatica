import 'Electronica.dart';
import 'Motor.dart';
import 'TrenRodaje.dart';
import 'TipoMoto.dart';
import 'Asiento.dart';
import 'Chasis.dart';

abstract class Builder {
  void setMotoTipo(TipoMoto tipo);
  void setChasis(Chasis chasis);
  void setAsientos(Asiento asiento);
  void setMotor(Motor motor);
  void setTrenRodaje(TrenRodaje trenRodaje);
  void setElectronica(Electronica electronica);
}
