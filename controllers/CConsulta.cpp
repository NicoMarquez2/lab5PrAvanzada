#include "CConsulta.h"
#include <ctime>
#include <algorithm>

CUsuario* CU = CUsuario::getInstancia();

CConsulta* CConsulta::instancia = NULL;

CConsulta::CConsulta(){}

CConsulta* CConsulta::getInstancia(){
    if (instancia == NULL)
        instancia = new CConsulta();
    return instancia;
}

void CConsulta::cargarDatos(vector<Consulta*> consultas, map<string, Diagnostico*> diagnosticos, vector<CodDiagnostico*> codigos){
    this->consultas = consultas;
    this->diagnosticos = diagnosticos;
    this->codigos = codigos;
}
void CConsulta::cargarDatos(vector<CodDiagnostico*> codigos){
    this->codigos = codigos;
}

vector<Consulta*> CConsulta::getConsultas(){
    return this->consultas;
}
map<string, Diagnostico*> CConsulta::getDiagnosticos(){
    return this->diagnosticos;
}
vector<CodDiagnostico*> CConsulta::getCodigos(){
    return this->codigos;
}
vector<DtCodDiagnostico> CConsulta::obtenerCodDiagnosticos(){
    vector<DtCodDiagnostico> setDtCD;
    DtCodDiagnostico DtCD;
    vector<CodDiagnostico*>::iterator it;
    for (it=codigos.begin(); it!=codigos.end(); ++it){
        CodDiagnostico *cod = *it;
        DtCD = DtCodDiagnostico(cod->getCodigoCategoria(), cod->getCategoria(), cod->getCodigoDiagnostico(), cod->getEtiqueta());
        setDtCD.push_back(DtCD);
    }
    return setDtCD;
}

void CConsulta::setConsultas(vector<Consulta*> consultas){
    this->consultas = consultas;
}
void CConsulta::setDiagnosticos(map<string, Diagnostico*> diagnosticos){
    this->diagnosticos = diagnosticos;
}
void CConsulta::setCodigos(vector<CodDiagnostico*> codigos){
    this->codigos = codigos;
}

vector<DtConsulta> CConsulta::obtenerConsultas(){}
DtConsulta CConsulta::seleccionarConsulta(string ci){}
void CConsulta::obtenerCategorias(){}
void CConsulta::seleccionarCategoria(string categoria){}
void CConsulta::seleccionarDiagnostico(string diagnostico){}
void CConsulta::agregarDescripcion(string descripcion){}
void CConsulta::agregarTratamiento(string descripcion, string tipo){}
void CConsulta::agregarFecha(Fecha fecha){}
void CConsulta::agregarMedicamento(string medicamento){}

void CConsulta::reservaConsulta(Fecha f, Hora h, string ciSoc, string ciMed){
    map<string,Usuario*> users = CU->getUsuarios();

    map<string, Usuario*>::iterator it;
    Usuario* m;
    Usuario* s;
    Consulta* c;
    time_t now = time(nullptr);
    tm* ltm = localtime(&now);
    Fecha ahora = Fecha(1900 + ltm->tm_year, 1 + ltm->tm_mon, ltm->tm_mday);
    it = users.find(ciMed);
    if (it != users.end()) {
        m = it->second;
    }
    it = users.find(ciSoc);
    if (it != users.end()) {
        s = it->second;
        c = new Reserva(f, h, s, m, ahora);
        this->consultas.push_back(c);
        CU->reservaConsultaUser(s, c);
        it = users.find(ciMed);
        if (it != users.end()) {
            m = it->second;
            CU->reservaConsultaUser(m, c);
        }
    }
}

void CConsulta::registroReserva(string ciMed, string ciPac, Fecha fecha, Fecha fechaReserva){
    map<string,Usuario*> users = CU->getUsuarios();

    map<string, Usuario*>::iterator it;
    Usuario* med;
    Usuario* pac;

    vector<DtReserva> rmed;
    vector<DtReserva> rpac;
    vector<DtReserva>::iterator it2;
    bool rmedexiste = false;
    bool rpacexiste = false;
    
    vector<Consulta*> consultas = this->consultas;
    

    it = users.find(ciMed);
    if (it != users.end()) {
        med = it->second;
        rmed = med->obtenerReservas();
    }
    it = users.find(ciPac);
    if (it != users.end()) {
        pac = it->second;
        rpac = pac->obtenerReservas();
    }
    for (it2=rmed.begin(); it2!=rmed.end(); ++it2) {
        Fecha fechaCon = it2->getFecha();
        Fecha fechaRes = it2->getFechaReserva();
        if (fechaCon.getDia() == fecha.getDia() & fechaRes.getDia() == fechaReserva.getDia()){
            rmedexiste = true;
        }
    }
    for (it2=rpac.begin(); it2!=rpac.end(); ++it2) {
        Fecha fechaCon = it2->getFecha();
        Fecha fechaRes = it2->getFechaReserva();
        if (fechaCon.getDia() == fecha.getDia() & fechaRes.getDia() == fechaReserva.getDia()){
            rpacexiste = true;
        }
    }
    if (rmedexiste && rpacexiste){
        auto it3 = find_if(consultas.begin(), consultas.end(), [&fecha, &fechaReserva](Consulta* consulta) {
                Reserva* reserva = dynamic_cast<Reserva*>(consulta);
                return reserva != nullptr 
                && reserva->getFecha().getDia() == fecha.getDia() 
                && reserva->getFechaReserva().getDia() == fechaReserva.getDia();
            });
        if (it3 != consultas.end()) {
            Reserva* encontroReserva = dynamic_cast<Reserva*>(*it3);
            if (encontroReserva) {
                encontroReserva->setAsiste(true);
            }
        } else {
        }
    }
}

void CConsulta::registroEmergencia(string ciMed, string ciPac, Fecha fecha, string motivo){  
    map<string,Usuario*> users = CU->getUsuarios();

    map<string, Usuario*>::iterator it;
    Usuario* med;
    Usuario* pac;
    Emergencia* e;

    it = users.find(ciMed);
    if (it != users.end()) {
        med = it->second;
    }
    it = users.find(ciPac);
    if (it != users.end()) {
        pac = it->second;
        e = new Emergencia(fecha, Hora(), pac, med, motivo);
        this->consultas.push_back(e);
    }
}
void CConsulta::listarRepresentacionesEstandarizadas(){}

void CConsulta::altaDiagnostico(string ciPac, string ciMed, string codCat, string codDiag, string desc){
    vector<Consulta*> consultas = this->consultas;
    vector<CodDiagnostico*> codigos = this->codigos;

    CodDiagnostico* codigoDiagnostico;

    auto it2 = find_if(codigos.begin(), codigos.end(), [&codCat, &codDiag](CodDiagnostico* codDiagnostico) {
                return codDiagnostico != nullptr
                && codDiagnostico->getCodigoCategoria() == codCat
                && codDiagnostico->getCodigoDiagnostico() == codDiag;
    });
    if  (it2 != codigos.end()) {
        codigoDiagnostico = *it2;
    }

    time_t now = time(nullptr);
    tm* ltm = localtime(&now);
    Fecha ahora = Fecha(1900 + ltm->tm_year, 1 + ltm->tm_mon, ltm->tm_mday);

    auto it = find_if(consultas.begin(), consultas.end(), [&ciPac, &ciMed, &ahora](Consulta* consulta) {
                return consulta != nullptr 
                && consulta->getSocio()->getCedula() == ciPac
                && consulta->getMedico()->getCedula() == ciMed
                && consulta->getFecha().getDia() == ahora.getDia();  
    });
    if (it != consultas.end()) {
        Consulta* encontroConsulta = *it;
        Diagnostico* diagnostico = new Diagnostico(codigoDiagnostico, desc);
        string descripcion = diagnostico->getDescripcion();
        this->diagnosticos.insert({descripcion, diagnostico});
        encontroConsulta->agregarDiagnostico(diagnostico);
    }

}

map<string, DtDiagnostico> CConsulta::obtenerDiagnosticos(){
    map<string, DtDiagnostico> setDtD;
    DtDiagnostico DtD;
    DtCodDiagnostico DtCD;
    map<string, Diagnostico*>::iterator it;

    for (it=diagnosticos.begin(); it!=diagnosticos.end(); ++it){
        Diagnostico *diag = it->second;
        DtCodDiagnostico * DtCodD = new DtCodDiagnostico(diag->getCodDiagnostico()->getCodigoCategoria(), diag->getCodDiagnostico()->getCategoria(),
                                    diag->getCodDiagnostico()->getCodigoDiagnostico(), diag->getCodDiagnostico()->getEtiqueta());
        DtCD = *DtCodD;
        DtDiagnostico *DtDiag = new DtDiagnostico(DtCD, diag->getDescripcion());
        DtD = *DtDiag;
        string desc = DtD.getDescripcion();
        setDtD.insert({desc, DtD});
    }
    return setDtD;
}