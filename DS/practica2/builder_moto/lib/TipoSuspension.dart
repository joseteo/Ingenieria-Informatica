enum TipoSuspension { DURA, MEDIA, BLANDA }

extension ParseToString on TipoSuspension {
  String toShortString() {
    switch (this) {
      case TipoSuspension.DURA:
        return "Dura";
      case TipoSuspension.MEDIA:
        return "Media";
      case TipoSuspension.BLANDA:
        return "Blanda";
      default:
        return "Sin tipo de suspensión";
    }
  }
}
