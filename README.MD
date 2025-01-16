# MP-T2-24.2

Este repositório contém o código e documentação do projeto **MP-T2-24.2**.  
Abaixo estão descritas as tecnologias utilizadas e as instruções para instalação das dependências necessárias.

---

## Tecnologias Usadas

O projeto utiliza as seguintes tecnologias:

- **C++**: Linguagem principal de desenvolvimento.
- **CMake**: Ferramenta para automatizar o processo de build.
- **GCov**: Ferramenta para análise de cobertura de código.
- **CPPLint**: Ferramenta para verificação de estilo de código C++.
- **CppCheck**: Ferramenta para análise estática de código.
- **Doxygen**: Gerador de documentação automatizada.
- **Chocolatey**: Gerenciador de pacotes para instalação de dependências no Windows.

---

## Como Instalar as Tecnologias

Siga os passos abaixo para configurar o ambiente necessário:

### 1. Instalar o Chocolatey
O **Chocolatey** é um gerenciador de pacotes para Windows que facilita a instalação de ferramentas.

1. Abra o **PowerShell** como administrador.
2. Execute o seguinte comando para instalar o Chocolatey:
   ```powershell
   Set-ExecutionPolicy Bypass -Scope Process -Force; [System.Net.ServicePointManager]::SecurityProtocol = [System.Net.SecurityProtocolType]::Tls12; iex ((New-Object System.Net.WebClient).DownloadString('https://community.chocolatey.org/install.ps1'))
