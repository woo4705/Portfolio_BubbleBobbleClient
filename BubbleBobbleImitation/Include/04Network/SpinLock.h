//��Ƽ�����忡�� �����ڿ��� ������ �������� Lock
#pragma once

/*�ܺ� MFC�� �������� �ʱ����� ������
#define WIN32_LEAN_AND_MEAN�� #include "windows.h" ���� ������ ������ �شٸ�
������ ����� ��Ŭ��� �ϸ鼭 �ߺ� ��Ŭ��� �Ǵ� ����� �����ϰ� �������� �ߺ����Ǹ� �����ϸ�
SDK ���α׷��ֿ� �ʿ���� ���ǵ��� �ǳʶڴ�. �׷��� ���α׷��� �����ϰ� ����� �ش�.
��ó: https://javawoo.tistory.com/42
*/
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

namespace Network {
	const int SpinlockCount = 1000;

	//����ڰ� �Ӱ迵���� ���� ��ü���� ������ Deadlock�� �ɸ��Ƿ�
	//�̸� �����ϱ����� �ڵ����� �Ҹ�� ��ü�ϰ� ������
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
		//��� �ʱ�ȭ ����Ʈ
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