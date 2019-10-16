//멀티쓰레드에서 공유자원의 접근을 막기위한 Lock
#pragma once

/*외부 MFC를 포함하지 않기위해 정의함
#define WIN32_LEAN_AND_MEAN를 #include "windows.h" 문장 이전에 선언해 준다면
수많은 헤더를 인클루드 하면서 중복 인클루드 되는 헤더를 방지하고 데이터의 중복정의를 제거하며
SDK 프로그래밍에 필요없는 정의들을 건너뛴다. 그래서 프로그램을 날씬하게 만들어 준다.
출처: https://javawoo.tistory.com/42
*/
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

namespace Network {
	const int SpinlockCount = 1000;

	//사용자가 임계영역을 수동 해체하지 않으면 Deadlock이 걸리므로
	//이를 방지하기위해 자동으로 소멸시 해체하게 만들음
	struct SpinLockCriticalSection
	{
		CRITICAL_SECTION m_CS;
		SpinLockCriticalSection() {
			InitializeCriticalSectionAndSpinCount(&m_CS, SpinlockCount);
		}
		~SpinLockCriticalSection() {

			DeleteCriticalSection(&m_CS);
		}
	};


	class SpinLockGuard {
	public:
		//멤버 초기화 리스트
		explicit SpinLockGuard(SpinLockCriticalSection* pCS)
			: m_pSpinCS(&pCS->m_CS)
		{
			EnterCriticalSection(m_pSpinCS);
		}

		~SpinLockGuard() {
			LeaveCriticalSection(m_pSpinCS);
		}

	private:
		CRITICAL_SECTION* m_pSpinCS = nullptr;
	};


};