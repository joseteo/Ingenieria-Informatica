import 'Electronica.dart';
import 'Motor.dart';
import 'TrenRodaje.dart';
import 'TipoMoto.dart';
import 'Asiento.dart';
import 'Chasis.dart';

abstract class Builder {
  void setMotoTipo({TipoMoto tipo = TipoMoto.MOTODEPORTIVA});
  void setChasis({Chasis chasis});
  void setAsientos({Asiento asiento});
  void setMotor();
  void setTrenRodaje();
  void setElectronica();
}
