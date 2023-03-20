#pragma once

template<typename T>
class singletonBase
{
protected:
	static T* m_pInstance;
	// ������ �Ҹ��� �ܺο��� ���� ����
	singletonBase() {};
	virtual ~singletonBase() {};

	// ���� ������ ������
	singletonBase(const singletonBase&);
	singletonBase& operator = (const singletonBase&);

public:
	// �ν��Ͻ� ����
	static void createInstance()
	{
		// assert() �Լ�
		// ���� ��� �ƹ��͵� ��������, �����̸� �˾�â��
		// ������ ����ϰ� ����
		assert(!m_pInstance);
		// �ν��Ͻ� ����
		m_pInstance = new T();
	}

	static void releaseInstance()
	{
		assert(m_pInstance);
		delete m_pInstance;
		m_pInstance = NULL;
	}

	static T& getInstance()
	{
		return *m_pInstance;
	}
};

template<typename T>
T* singletonBase<T>::m_pInstance = nullptr;


