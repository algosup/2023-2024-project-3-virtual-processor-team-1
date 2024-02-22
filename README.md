# 2023-2024-project-3-virtual-processor

## Description

The goal of the project is to create a virtual processor and an interpreter for running assembly code on
that processor.
The project will be developed in plain, portable, C language without the use of any external library besides
C standard libraries.

## Documentation

[Project charter](https://github.com/algosup/2023-2024-project-3-virtual-processor-team-1/blob/main/Documents/ProjectCharter.md) by Elone DELILLE

[Functional specifications](https://github.com/algosup/2023-2024-project-3-virtual-processor-team-1/blob/main/Documents/FunctionalSpecifications.md) by Elone DELILLE

[Assembly2 documentation](https://algosup-t1.gitbook.io/asm2/) on GitBook by Elone DELILLE

[Technical specifications](https://github.com/algosup/2023-2024-project-3-virtual-processor-team-1/blob/main/Documents/TechnicalSpecifications.md) by Thomas PLANCHARD

[Test plan](https://github.com/algosup/2023-2024-project-3-virtual-processor-team-1/blob/main/Documents/TestPlan.md) by Séréna BAVAROIS

## Management

The management artifacts of this project are available on our [Jira project](https://virtual-processor.atlassian.net/jira/core/projects/VPT1/summary).

Here is a [Tutorial](/Documents/JiraTutorial.md) to help you to find specific documents. On this Jira project, you will find the task allocation, the timeline, and all the documents related to the management.

## Installation

To install the project, you need to clone the repository and build the project with the following commands:

### Windows

```bash
git clone <https://github.com/algosup/2023-2024-project-3-virtual-processor-team-1>
cd <2023-2024-project-3-virtual-processor-team-1/Src>
gcc interpreter.c -o interpreter.exe
.\interpreter.exe <path_to_your_asm2_file>
```

### MacOS

```bash
git clone <https://github.com/algosup/2023-2024-project-3-virtual-processor-team-1>
cd <2023-2024-project-3-virtual-processor-team-1/Src>
gcc interpreter.c -o interpreter
./interpreter <path_to_your_asm2_file>
```

## Team Members

| **Photo** | **Name** | **Role** | **GitHub and LinkedIn** |
|---|---|---|---|
| ![Clémentine Curel](https://ca.slack-edge.com/T06BWRNMW3X-U06C7TXB9PE-g35ba02d7e83-64) | CUREL Clémentine | Project Manager | [GitHub](https://github.com/Clementine951) \| [LinkedIn](https://www.linkedin.com/in/clementine-curel/) |
| ![Elone Delille](https://ca.slack-edge.com/T06BWRNMW3X-U06CNHASLBS-gd0f64565afd-64) | DELILLE Elone | Program Manager | [GitHub](https://github.com/HiNett) \| [LinkedIn](https://www.linkedin.com/in/elonedelille/) |
| ![Thomas Planchard](https://ca.slack-edge.com/T019N8PRR7W-U02EY24GTT8-ge73464278d5-64) | PLANCHARD Thomas | Technical Leader | [GitHub](https://github.com/thomas-planchard) \| [LinkedIn](https://www.linkedin.com/in/thomas-planchard-461782221/) |
| ![Alexis Lasselin](https://ca.slack-edge.com/T06BWRNMW3X-U06BZPTBDV0-g00cd520ab1f-64) | LASSELIN Alexis | Software Engineer | [GitHub](https://github.com/AlexisLasselin) \| [LinkedIn](https://www.linkedin.com/in/alexis-lasselin-318649251/) |
| ![Salaheddine Namir](https://ca.slack-edge.com/T06BWRNMW3X-U06CMQRP3D4-gfbb2631ed2b-64) | NAMIR Salaheddine | Software Engineer | [GitHub](https://github.com/T3rryc) \| [LinkedIn](https://www.linkedin.com/in/salaheddine-namir-3402471b8/) |
| ![Séréna Bavarois](https://ca.slack-edge.com/T06BWRNMW3X-U06C1D5D9RT-g2a7db03edc5-64) | BAVAROIS Séréna | Quality Assurance | [GitHub](https://github.com/NanaChocolat) \| [LinkedIn](https://www.linkedin.com/in/s%C3%A9r%C3%A9na-bavarois-619975218/) |
