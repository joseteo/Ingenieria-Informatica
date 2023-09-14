import 'Reloj.dart';

int totalHorasCompletas(int totalMinutos) {
  return totalMinutos ~/ 60;
}

Object totalHoras(int totalMinutos) {
  double horas = totalMinutos / 60;
  return horas;
}

void main() async {
  const constante = "constante";
  var generica = Object();

  print(constante);
  print(generica);

  final reloj = Reloj(3, 30, 33);
  final reloj2 = Reloj(15, 45, 59);
  final reloj3 = Reloj.Reloj();

  print(await reloj.refreshToString(reloj));
  print(await reloj2.refreshToString(reloj));
  print(await reloj3.refreshToString(reloj));

  print(reloj.toString());
  print("Total horas en minutos: ${reloj.totalHoraEnMinutosP()}");

  final horasTotales = totalHoras(reloj2.totalHoraEnMinutosP());
  final horasCompletas = totalHorasCompletas(reloj3.totalHoraEnMinutosP());

  print("Horas totales (con parte decimal): $horasTotales");
  print("Horas completas (division entera): $horasCompletas");
}
