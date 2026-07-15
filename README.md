# ConsoleMVC-donggeon-0119

C++ 콘솔 애플리케이션에서 **MVC(Model / View / Controller)** 아키텍처 패턴을 검증하기 위한 PoC(Proof of Concept) 리포지토리입니다.

## 배경

이 프로젝트는 "S-Semi" 반도체 회사의 **시료(Sample) 생산주문관리 시스템**을 본 개발에 앞서, 먼저 MVC 구조가 콘솔 환경에서도 올바르게 역할 분리될 수 있는지 검증하기 위한 PoC입니다.


## 이 리포지토리의 목적

실제 업무 로직(주문 승인, 생산 큐, 재고 계산 등)의 완성이 아니라, **시료(Sample)·주문(Order) 도메인을 예시로 삼아 Model / View / Controller 각 계층이 서로의 책임을 침범하지 않고 분리되는 구조**를 검증하는 것이 목표입니다.

## 아키텍처

- **Model**: 시료(Sample), 주문(Order) 등 도메인 데이터와 데이터 조작 로직을 담당합니다. View나 Controller에 의존하지 않습니다.
- **View**: 콘솔 입출력만 담당합니다. 메뉴 출력, 목록 표시, 사용자 입력 수신만 처리하며 비즈니스 로직을 포함하지 않습니다.
- **Controller**: View의 입력을 받아 Model을 조작하고, 처리 결과를 View에 반영하도록 흐름을 제어합니다.

```
User Input → View → Controller → Model
                ↑                   │
                └── 결과 반영 ───────┘
```

## 폴더 구조

```
ConsoleMVC-donggeon-0119/
├─ ConsoleMVC-donggeon-0119.sln
└─ ConsoleMVC-donggeon-0119/
   ├─ ConsoleMVC-donggeon-0119.vcxproj
   ├─ Model/          # Sample, Order 등 도메인 데이터 및 로직
   ├─ View/           # 콘솔 입출력 담당
   └─ Controller/     # Model과 View를 연결하는 흐름 제어
```

> 폴더 구조는 구현 진행에 따라 추가/변경될 수 있습니다.

## 개발 환경

- 언어: C++
- IDE: Visual Studio 2022 (v17)
- 플랫폼: Win32 / x64, Debug / Release

## 빌드 및 실행

1. `ConsoleMVC-donggeon-0119.sln`을 Visual Studio로 엽니다.
2. 원하는 구성(Debug/Release)과 플랫폼(x86/x64)을 선택합니다.
3. 빌드 후 실행합니다.
