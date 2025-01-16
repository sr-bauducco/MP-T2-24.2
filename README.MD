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
```

2. Instalar o C++
MinGW (via Chocolatey)
Com o Chocolatey instalado, execute:
bash
Copiar
Editar
choco install mingw
Microsoft Visual Studio
Baixe e instale o Visual Studio Community.
Durante a instalação, selecione a carga de trabalho "Desenvolvimento de desktop com C++".
3. Instalar o CMake
Execute o comando no PowerShell (com o Chocolatey):
bash
Copiar
Editar
choco install cmake
4. Instalar o GCov
O GCov está incluído no GCC, que é instalado com o MinGW:
bash
Copiar
Editar
choco install mingw
Verifique a instalação com:
bash
Copiar
Editar
gcov --version
5. Instalar o CPPLint
Certifique-se de ter o Python instalado.
Use o comando:
bash
Copiar
Editar
pip install cpplint
6. Instalar o CppCheck
Instale o CppCheck com o Chocolatey:
bash
Copiar
Editar
choco install cppcheck
7. Instalar o Doxygen
Instale o Doxygen com o Chocolatey:
bash
Copiar
Editar
choco install doxygen
Alternativamente, baixe o Doxygen do site oficial: Doxygen Downloads.