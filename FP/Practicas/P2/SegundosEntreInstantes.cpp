#include <iostream>

using namespace std;

int main(){
	int h_ini=0, m_ini=0, s_ini=0, s_total_ini=0,
	h_fin=0, m_fin=0, s_fin=0, s_dif=0, s_total_fin=0;
	
	cout << "Introduce el instante inicial(horas 0-23, minutos 0-59, segundos 0-59): ";
	cin >> h_ini >> m_ini >> s_ini;
	cout << "Introduce el instante final(horas 0-23, minutos 0-59, segundos 0-59): ";
	cin >> h_fin >> m_fin >> s_fin;
	
	s_total_ini = h_ini*3600 + m_ini*60 + s_ini;
	s_total_fin = h_fin*3600 + m_fin*60 + s_fin;
	
	s_dif = s_total_fin - s_total_ini;
	
	cout << "\nSegundos entre los dos instantes: " << s_dif << endl;
	
	return 0;
}
