import 'TipoFrenos.dart';
import 'TipoSuspension.dart';

class TrenRodaje {
  int _pulgadaRueda;
  TipoFrenos _tipoFrenos;
  TipoSuspension _tipoSuspension;

  TrenRodaje(
      this._pulgadaRueda,
      this._tipoFrenos,
      this._tipoSuspension,
      );

  int get pulgadaRueda => _pulgadaRueda;
  TipoFrenos get tipoFrenos => _tipoFrenos;
  TipoSuspension get tipoSuspension => _tipoSuspension;


  set pulgadaRueda(int pulgadaRueda) {
    _pulgadaRueda = pulgadaRueda;
  }

  set tipoFrenos(TipoFrenos tipoFrenos) {
    _tipoFrenos = tipoFrenos;
  }

  set tipoSuspension(TipoSuspension tipoSuspension) {
    _tipoSuspension = tipoSuspension;
  }

  @override
  String toStringTipoSuspension() {
    _tipoSuspension.toString();
    return toString();
  }
}
