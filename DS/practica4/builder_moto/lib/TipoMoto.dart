enum TipoMoto { MOTODEPORTIVA, MOTOSCOOTER, MOTOTOURING }

extension ParseToString on TipoMoto {
  String toShortString() {
    switch (this) {
      case TipoMoto.MOTODEPORTIVA:
        return "Moto Deportiva";
      case TipoMoto.MOTOSCOOTER:
        return "Moto Scooter";
      case TipoMoto.MOTOTOURING:
        return "Moto Touring";
      default:
        return "Sin tipo de moto";
    }
  }
}
