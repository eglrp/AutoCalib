#ifndef _ECAT_GUI_MyTitleBar_H_
#define _ECAT_GUI_MyTitleBar_H_

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QTimer>

enum ButtonType
{
	MIN_BUTTON = 0,
	MIN_MAX_BUTTON = 1,
	ONLY_CLOSE_BUTTON
};

class MyTitleBar : public QWidget
{
	Q_OBJECT
public:
	MyTitleBar(QWidget *parent = NULL);
	~MyTitleBar();

	//���ñ���������ɫ
	void setBackgroundColor(int r, int g, int b);
	//���ñ�����ͼ��
	void setTitleIcon(QString filePath);
	//���ñ�������
	void setTitleContent(QString titleContent);
	//���ñ���������
	void setTitleWidth(int width);
	//���ñ������ϰ�ť������
	void setButtonType(ButtonType buttonType);
	//���ñ������еı����Ƿ�����
	void setTitleRoll();

	//���桢��ȡ�����С�����ڵ�λ�ü���С
	void saveRestoreInfo(const QPoint point, const QSize size);
	void getRestoreInfo(QPoint& point, QSize& size);

private:
	void paintEvent(QPaintEvent *event);
	void mouseDoubleClickEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void mousePressEvent(QMouseEvent *event);

	//��ʼ���ؼ�
	void initControl();
	//�źŲ۵İ�
	void initConnections();
	//������ʽ�ļ�
	void loadStyleSheet(const QString &sheetName);

signals:
	//��ť�������ź�
	void signalButtonMinClicked();
	void signalButtonRestoreClicked();
	void signalButtonMaxClicked();
	void signalButtonCloseClicked();

private slots:
	// ��ť�����Ĳ�;
	void onButtonMinClicked();
	void onButtonRestoreClicked();
	void onButtonMaxClicked();
	void onButtonCloseClicked();
	void onRollTitle();

private:
	QLabel* m_pIcon;			//������ͼ��
	QLabel* m_pTitleContent;	//����������
	QPushButton* m_pButtonMin;
	QPushButton* m_pButtonRestore;
	QPushButton* m_pButtonMax;
	QPushButton* m_pButtonClose;

	//����������ɫ
	int m_colorR;
	int m_colorG;
	int m_colorB;

	//��󻯡���С������
	QPoint m_restorePos;
	QSize m_restoreSize;
	//�ƶ����ڵı���
	bool m_isPressed;
	QPoint m_startMovePos;
	//�����������Ч��ʱ��
	QTimer m_titleRollTimer;
	//����������
	QString m_titleContent;
	//��ť����
	ButtonType m_buttonType;
};
#endif