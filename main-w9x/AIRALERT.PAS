unit Airalert;

interface

uses
  SysUtils, WinTypes, WinProcs, Messages, Classes, Graphics, Controls,
  Forms, Dialogs, StdCtrls, ExtCtrls, Menus, Gauges, Unit2,
  IdBaseComponent, IdComponent, IdTCPConnection, IdTCPClient, IdHTTP,
  ActnList, IdTime, Windows, IdException, DateUtils, ShellApi;

type
  TForm1 = class(TForm)
    GroupBox1: TGroupBox;
    webStatus: TPanel;
    MainMenu1: TMainMenu;
    File1: TMenuItem;
    Help1: TMenuItem;
    About1: TMenuItem;
    Exit1: TMenuItem;
    Panel2: TPanel;
    mapPh: TImage;
    debugButtonTab: TMenuItem;
    regChernih: TImage;
    regPolt: TImage;
    regSum: TImage;
    regKha: TImage;
    regDon: TImage;
    regLuh: TImage;
    regDn: TImage;
    regZap: TImage;
    regKher: TImage;
    regCrimea: TImage;
    regMyk: TImage;
    regOdes: TImage;
    regKyro: TImage;
    regCherk: TImage;
    regKyiv: TImage;
    regZhyt: TImage;
    regRivn: TImage;
    regVol: TImage;
    regLviv: TImage;
    regZak: TImage;
    regIvano: TImage;
    regTern: TImage;
    regChmeln: TImage;
    regVin: TImage;
    regCherniv: TImage;
    regKyivCity: TImage;
    Timer1: TTimer;
    Deselect1: TMenuItem;
    Fullscreen1: TMenuItem;
    Update1: TMenuItem;
    statusBox: TGroupBox;
    statusVin: TImage;
    Label4: TLabel;
    Label5: TLabel;
    Image2: TImage;
    Label6: TLabel;
    Label7: TLabel;
    Label8: TLabel;
    Label9: TLabel;
    Label10: TLabel;
    Label11: TLabel;
    Label12: TLabel;
    Label13: TLabel;
    Label14: TLabel;
    Label15: TLabel;
    Label16: TLabel;
    Label17: TLabel;
    Label18: TLabel;
    Label19: TLabel;
    Label20: TLabel;
    Label21: TLabel;
    Label22: TLabel;
    Label23: TLabel;
    Label24: TLabel;
    Label25: TLabel;
    Label26: TLabel;
    Label27: TLabel;
    Label28: TLabel;
    Label29: TLabel;
    Image3: TImage;
    Image4: TImage;
    Image5: TImage;
    Image6: TImage;
    Image7: TImage;
    Image8: TImage;
    Image9: TImage;
    Image10: TImage;
    Image11: TImage;
    Image12: TImage;
    Image13: TImage;
    Image27: TImage;
    Image28: TImage;
    Image29: TImage;
    Image30: TImage;
    Image31: TImage;
    Image32: TImage;
    Image33: TImage;
    Image34: TImage;
    Image35: TImage;
    Image36: TImage;
    Image37: TImage;
    Image38: TImage;
    Image39: TImage;
    Image40: TImage;
    statusZak: TImage;
    statusKyivCity: TImage;
    statusVol: TImage;
    statusDn: TImage;
    statusDon: TImage;
    statusZhyt: TImage;
    statusZap: TImage;
    statusIvano: TImage;
    statusKyiv: TImage;
    statusKyro: TImage;
    statusLuh: TImage;
    statusLviv: TImage;
    statusMyk: TImage;
    statusOdes: TImage;
    statusPolt: TImage;
    statusRivn: TImage;
    statusSum: TImage;
    statusTern: TImage;
    statusKha: TImage;
    statusKher: TImage;
    statusChmeln: TImage;
    statusCherk: TImage;
    statusCherniv: TImage;
    statusChernih: TImage;
    statusCrimea: TImage;
    Image1: TImage;
    Image41: TImage;
    netStatus: TLabel;
    Language1: TMenuItem;
    UAlang: TMenuItem;
    ENlang: TMenuItem;
    Settings1: TMenuItem;
    Connect1: TMenuItem;
    Disconnect1: TMenuItem;
    Connect2: TMenuItem;
    ChooseServer1: TMenuItem;
    Try1: TMenuItem;
    Panel1: TPanel;
    Label3: TLabel;
    countdown: TLabel;
    onlineStatus: TImage;
    Status: TLabel;
    IdHTTP1: TIdHTTP;
    noWeb: TImage;
    Image44: TImage;
    callapi: TButton;
    Panel3: TPanel;
    dateText: TLabel;
    clockTimer: TLabel;
    Label31: TLabel;
    daySince: TLabel;
    Help2: TMenuItem;
    am12: TImage;
    am1: TImage;
    am2: TImage;
    am3: TImage;
    am4: TImage;
    am5: TImage;
    am6: TImage;
    am7: TImage;
    am8: TImage;
    am9: TImage;
    am10: TImage;
    am11: TImage;
    pm12: TImage;
    pm1: TImage;
    pm2: TImage;
    pm3: TImage;
    pm4: TImage;
    pm5: TImage;
    pm6: TImage;
    pm7: TImage;
    pm8: TImage;
    pm9: TImage;
    pm10: TImage;
    pm11: TImage;
    Crash1: TMenuItem;
    Timer2: TTimer;
    Button4: TButton;
    throbber: TImage;
    updateBtn: TButton;
    Button5: TButton;
    Button3: TButton;
    Button6: TButton;
    Edit1: TEdit;
    procedure About1Click(Sender: TObject);
    procedure Exit1Click(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    procedure updateBtnClick(Sender: TObject);
    procedure request(Sender: TObject);
    procedure callapiClick(Sender: TObject);
    procedure Connect2Click(Sender: TObject);
    procedure Disconnect1Click(Sender: TObject);
    procedure Crash1Click(Sender: TObject);
    procedure Button4Click(Sender: TObject);
    procedure Button3Click(Sender: TObject);
    procedure Button5Click(Sender: TObject);
    procedure Update1Click(Sender: TObject);
    procedure Button6Click(Sender: TObject);
    procedure Help2Click(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form1: TForm1;
  debugMode : boolean;
  sec : integer;
  cdNatur : boolean;
    VinStatus : string;
    VolStatus : string;
    DnStatus : string;
    DonStatus : string;
    ZhytStatus : string;
    ZakStatus : string;
    ZapStatus : string;
    IvanoStatus : string;
    KyivStatus : string;
    KiroStatus : string;
    LuhStatus : string;
    LvivStatus : string;
    MykStatus : string;
    OdesStatus : string;
    PoltStatus : string;
    RivStatus : string;
    SumStatus : string;
    TernStatus : string;
    KhaStatus : string;
    KheStatus : string;
    KhmelnStatus : string;
    CherkStatus : string;
    ChernivStatus : string;
    ChernihStatus : string;
    CrimeaStatus : string;
    KyivCityStatus : string;
    statusC : boolean;
    SystemTime : TSystemTime;
    Hour : string;
    onceT : integer;
    noWebCon : boolean;
    disconnect : boolean;

implementation

{$R *.DFM}

procedure TForm1.About1Click(Sender: TObject);
begin
     AboutBox.Show;
end;

procedure TForm1.Exit1Click(Sender: TObject);
begin
     Application.Terminate;
end;

procedure TForm1.Request(Sender: TObject);
var
inp : string;
begin
    if noWebCon = true then
    begin
        // do nothing
    end else if noWebCon = false then
    begin
    if onceT = 0 then
    begin
        Button4Click(Form1);
        onceT := 1;
    end;
    if debugMode = false then
        begin
        Form1.countdown.Caption := inttostr(sec);
        sec := sec-1;
        if sec = -2 then
                begin
                Form1.Timer1.Enabled := false;
                updateBtnClick(Form1);
                callapiClick(Form1);
                end;
    end;
    end;
end;

procedure SetDefaults();
begin
     Form1.Status.Caption := 'Offline';
     Form1.onlineStatus.Visible := false;

     Form1.throbber.visible := false;

     Form1.noWeb.Visible := false;
     Form1.webStatus.Caption := '';
     Form1.netStatus.Visible := false;

     Form1.Height := 323;
     Form1.Width := 537;

     Form1.debugButtonTab.Checked := false;
     Form1.webStatus.Caption := 'Connecting...';

     Form1.regVol.Visible := false;
     Form1.regLviv.Visible := false;
     Form1.regZak.Visible := false;
     Form1.regRivn.Visible := false;
     Form1.regTern.Visible := false;
     Form1.regIvano.Visible := false;
     Form1.regZhyt.Visible := false;
     Form1.regChmeln.Visible := false;
     Form1.regCherniv.Visible := false;
     Form1.regChernih.Visible := false;
     Form1.regKyivCity.Visible := false;
     Form1.regKyiv.Visible := false;
     Form1.regVin.Visible := false;
     Form1.regSum.Visible := false;
     Form1.regPolt.Visible := false;
     Form1.regCherk.Visible := false;
     Form1.regKha.Visible := false;
     Form1.regDn.Visible := false;
     Form1.regKyro.Visible := false;
     Form1.regLuh.Visible := false;
     Form1.regDon.Visible := false;
     Form1.regZap.Visible := false;
     Form1.regKher.Visible := false;
     Form1.regMyk.Visible := false;
     Form1.regOdes.Visible := false;
     Form1.regCrimea.Visible := false;

     Form1.statusVol.Visible := false;
     Form1.statusLviv.Visible := false;
     Form1.statusZak.Visible := false;
     Form1.statusRivn.Visible := false;
     Form1.statusTern.Visible := false;
     Form1.statusIvano.Visible := false;
     Form1.statusZhyt.Visible := false;
     Form1.statusChmeln.Visible := false;
     Form1.statusCherniv.Visible := false;
     Form1.statusChernih.Visible := false;
     Form1.statusKyivCity.Visible := false;
     Form1.statusKyiv.Visible := false;
     Form1.statusVin.Visible := false;
     Form1.statusSum.Visible := false;
     Form1.statusPolt.Visible := false;
     Form1.statusCherk.Visible := false;
     Form1.statusKha.Visible := false;
     Form1.statusDn.Visible := false;
     Form1.statusKyro.Visible := false;
     Form1.statusLuh.Visible := false;
     Form1.statusDon.Visible := false;
     Form1.statusZap.Visible := false;
     Form1.statusKher.Visible := false;
     Form1.statusMyk.Visible := false;
     Form1.statusOdes.Visible := false;
     Form1.statusCrimea.Visible := false;
end;

procedure TForm1.FormCreate(Sender: TObject);
begin
{* Set parameters to defaults*}
     onceT := 0;
     SetDefaults();
     updateBtnClick(Form1);
     callapiClick(Form1);
end;

procedure regVolOn();
begin
       Form1.regVol.Visible := true;
       Form1.statusVol.Visible := true;
end;

procedure regVolOff();
begin
       Form1.regVol.Visible := false;
       Form1.statusVol.Visible := false;
end;

procedure regZakOn();
begin
       Form1.regZak.Visible := true;
       Form1.statusZak.Visible := true;
end;

procedure regZakOff();
begin
       Form1.regZak.Visible := false;
       Form1.statusZak.Visible := false;
end;

procedure regTernOn();
begin
       Form1.regTern.Visible := true;
       Form1.statusTern.Visible := true;
end;

procedure regTernOff();
begin
       Form1.regTern.Visible := false;
       Form1.statusTern.Visible := false;
end;

procedure regZhytOn();
begin
       Form1.regZhyt.Visible := true;
       Form1.statusZhyt.Visible := true;
end;

procedure regZhytOff();
begin
       Form1.regZhyt.Visible := false;
       Form1.statusZhyt.Visible := false;
end;

procedure regVinOn();
begin
       Form1.regVin.Visible := true;
       Form1.statusVin.Visible := true;
end;

procedure regVinOff();
begin
       Form1.regVin.Visible := false;
       Form1.statusVin.Visible := false;
end;

procedure regPoltOn();
begin
       Form1.regPolt.Visible := true;
       Form1.statusPolt.Visible := true;
end;

procedure regPoltOff();
begin
       Form1.regPolt.Visible := false;
       Form1.statusPolt.Visible := false;
end;

procedure regKhaOn();
begin
       Form1.regKha.Visible := true;
       Form1.statusKha.Visible := true;
end;

procedure regKhaOff();
begin
       Form1.regKha.Visible := false;
       Form1.statusKha.Visible := false;
end;

procedure regDnOn();
begin
       Form1.regDn.Visible := true;
       Form1.statusDn.Visible := true;
end;

procedure regDnOff();
begin
       Form1.regDn.Visible := false;
       Form1.statusDn.Visible := false;
end;

procedure regKyroOn();
begin
       Form1.regKyro.Visible := true;
       Form1.statusKyro.Visible := true;
end;

procedure regKyroOff();
begin
       Form1.regKyro.Visible := false;
       Form1.statusKyro.Visible := false;
end;

procedure regLuhOn();
begin
       Form1.regLuh.Visible := true;
       Form1.statusLuh.Visible := true;
end;

procedure regLuhOff();
begin
       Form1.regLuh.Visible := false;
       Form1.statusLuh.Visible := false;
end;

procedure regDonOn();
begin
       Form1.regDon.Visible := true;
       Form1.statusDon.Visible := true;
end;

procedure regDonOff();
begin
       Form1.regDon.Visible := false;
       Form1.statusDon.Visible := false;
end;

procedure regMykOn();
begin
       Form1.regMyk.Visible := true;
       Form1.statusMyk.Visible := true;
end;

procedure regMykOff();
begin
       Form1.regMyk.Visible := false;
       Form1.statusMyk.Visible := false;
end;

procedure regOdesOn();
begin
       Form1.regOdes.Visible := true;
       Form1.statusOdes.Visible := true;
end;

procedure regOdesOff();
begin
       Form1.regOdes.Visible := false;
       Form1.statusOdes.Visible := false;
end;

procedure regLvivOn();
begin
       Form1.regLviv.Visible := true;
       Form1.statusLviv.Visible := true;
end;

procedure regLvivOff();
begin
       Form1.regLviv.Visible := false;
       Form1.statusLviv.Visible := false;
end;

procedure regRivnOn();
begin
       Form1.regRivn.Visible := true;
       Form1.statusRivn.Visible := true;
end;

procedure regRivnOff();
begin
       Form1.regRivn.Visible := false;
       Form1.statusRivn.Visible := false;
end;

procedure regIvanoOn();
begin
       Form1.regIvano.Visible := true;
       Form1.statusIvano.Visible := true;
end;

procedure regIvanoOff();
begin
       Form1.regIvano.Visible := false;
       Form1.statusIvano.Visible := false;
end;

procedure regKyivOn();
begin
       Form1.regKyiv.Visible := true;
       Form1.statusKyiv.Visible := true;
end;

procedure regKyivOff();
begin
       Form1.regKyiv.Visible := false;
       Form1.statusKyiv.Visible := false;
end;

procedure regSumOn();
begin
       Form1.regSum.Visible := true;
       Form1.statusSum.Visible := true;
end;

procedure regSumOff();
begin
       Form1.regSum.Visible := false;
       Form1.statusSum.Visible := false;
end;

procedure regCherkOn();
begin
       Form1.regCherk.Visible := true;
       Form1.statusCherk.Visible := true;
end;

procedure regCherkOff();
begin
       Form1.regCherk.Visible := false;
       Form1.statusCherk.Visible := false;
end;

procedure regChmelnOn();
begin
       Form1.regChmeln.Visible := true;
       Form1.statusChmeln.Visible := true;
end;

procedure regChmelnOff();
begin
       Form1.regChmeln.Visible := false;
       Form1.statusChmeln.Visible := false;
end;

procedure regChernivOn();
begin
       Form1.regCherniv.Visible := true;
       Form1.statusCherniv.Visible := true;
end;

procedure regChernivOff();
begin
       Form1.regCherniv.Visible := false;
       Form1.statusCherniv.Visible := false;
end;

procedure regChernihOn();
begin
       Form1.regChernih.Visible := true;
       Form1.statusChernih.Visible := true;
end;

procedure regChernihOff();
begin
        Form1.regChernih.Visible := false;
        Form1.statusChernih.Visible := false;
end;

procedure regKyivCityOn();
begin
       Form1.regKyivCity.Visible := true;
       Form1.statusKyivCity.Visible := true;
end;

procedure regKyivCityOff();
begin
       Form1.regKyivCity.Visible := false;
       Form1.statusKyivCity.Visible := false;
end;

procedure regZapOn();
begin
       Form1.regZap.Visible := true;
       Form1.statusZap.Visible := true;
end;

procedure regZapOff();
begin
       Form1.regZap.Visible := false;
       Form1.statusZap.Visible := false;
end;

procedure regKherOn();
begin
       Form1.regKher.Visible := true;
       Form1.statusKher.Visible := true;
end;

procedure regKherOff();
begin
       Form1.regKher.Visible := false;
       Form1.statusKher.Visible := false;
end;

procedure regCrimeaOn();
begin
       Form1.regCrimea.Visible := true;
       Form1.statusCrimea.Visible := true;
end;

procedure regCrimeaOff();
begin
       Form1.regCrimea.Visible := false;
       Form1.statusCrimea.Visible := false;
end;

procedure TForm1.updateBtnClick(Sender: TObject);
var
        inp, dateGet, dateClean : string;
        StartPos : integer;
        fstYear, sndYear, trdYear, frtYear, fstMon, sndMon, fstDay, sndDay, fstHrs : string;
        YYYY, MM, DD : Word;
begin
        if debugMode = true then
        begin
        sec := 15;
        // do nothing
        end else if debugMode = false then
        begin
        sec := 15;
        throbber.Visible := false;

        Form1.noWeb.Visible := false;
        Form1.webStatus.Caption := '';
        Form1.netStatus.Visible := false;

        if SystemTime.wHour = 21 then
        begin
        pm9.BringToFront;
        end else if SystemTime.wHour = 22 then
        begin
        pm10.BringToFront;
        end else if SystemTime.wHour = 23 then
        begin
        pm11.BringToFront;
        end else if SystemTime.wHour = 00 then
        begin
        am12.BringToFront;
        end else if SystemTime.wHour = 01 then
        begin
        am1.BringToFront;
        end else if SystemTime.wHour = 02 then
        begin
        am2.BringToFront;
        end else if SystemTime.wHour = 03 then
        begin
        am3.BringToFront;
        end else if SystemTime.wHour = 04 then
        begin
        am4.BringToFront;
        end else if SystemTime.wHour = 05 then
        begin
        am5.BringToFront;
        end else if SystemTime.wHour = 06 then
        begin
        am6.BringToFront;
        end else if SystemTime.wHour = 07 then
        begin
        am7.BringToFront;
        end else if SystemTime.wHour = 08 then
        begin
        am8.BringToFront;
        end else if SystemTime.wHour = 09 then
        begin
        am9.BringToFront;
        end else if SystemTime.wHour = 10 then
        begin
        am10.BringToFront;
        end else if SystemTime.wHour = 11 then
        begin
        am11.BringToFront;
        end else if SystemTime.wHour = 12 then
        begin
        pm12.BringToFront;
        end else if SystemTime.wHour = 13 then
        begin
        pm1.BringToFront;
        end else if SystemTime.wHour = 14 then
        begin
        pm2.BringToFront;
        end else if SystemTime.wHour = 15 then
        begin
        pm3.BringToFront;
        end else if SystemTime.wHour = 16 then
        begin
        pm4.BringToFront;
        end else if SystemTime.wHour = 17 then
        begin
        pm5.BringToFront;
        end else if SystemTime.wHour = 18 then
        begin
        pm6.BringToFront;
        end else if SystemTime.wHour = 19 then
        begin
        pm7.BringToFront;
        end else if SystemTime.wHour = 20 then
        begin
        pm8.BringToFront;
        end;

        noWebCon := false;

        try
        inp := Form1.IdHTTP1.Get('http://ubilling.net.ua/aerialalerts/');
        Status.Caption := 'Online';
        onlineStatus.Visible := true;
        except
        on E: EIdSocketError do
        begin
        MessageBox(0,'No Internet Connection!', 'Air Alert', MB_ICONWARNING);
        noWeb.Visible := true;
        netStatus.Visible := true;
        onlineStatus.Visible := false;
        Status.Caption := 'Offline';
        countdown.Caption := '15';
        sec := 15;
        noWebCon := true;
        throbber.Visible := true;
        end;
        on D: EIdProtocolReplyError do
        begin
        MessageDlg(D.Message+'. Try again later.',mtError,[mbOK],0);
        noWeb.Visible := true;
        netStatus.Visible := true;
        onlineStatus.Visible := false;
        Status.Caption := 'Offline';
        countdown.Caption := '15';
        sec := 15;
        noWebCon := true;
        throbber.Visible := true;
        end;
        end;

        //inp := '';

        DeCodeDate (Date, YYYY, MM, DD);
        dateGet := format ('%d-%d-%d', [yyyy,mm,dd]);  // 2025-1-22

        webStatus.Caption := Hour;

        fstYear := copy(dateGet,1,1);
        sndYear := copy(dateGet,2,1);
        trdYear := copy(dateGet,3,1);
        frtYear := copy(dateGet,4,1);

        if copy(dateGet,6,2) = '1-' then
        begin
        fstMon := '0';
        sndMon := '1';
        end else if copy(dateGet,6,2) = '2-' then
        begin
        fstMon := '0';
        sndMon := '2';
        end else if copy(dateGet,6,2) = '3-' then
        begin
        fstMon := '0';
        sndMon := '3';
        end else if copy(dateGet,6,2) = '4-' then
        begin
        fstMon := '0';
        sndMon := '4';
        end else if copy(dateGet,6,2) = '5-' then
        begin
        fstMon := '0';
        sndMon := '5';
        end else if copy(dateGet,6,2) = '6-' then
        begin
        fstMon := '0';
        sndMon := '6';
        end else if copy(dateGet,6,2) = '7-' then
        begin
        fstMon := '0';
        sndMon := '7';
        end else if copy(dateGet,6,2) = '8-' then
        begin
        fstMon := '0';
        sndMon := '8';
        end else if copy(dateGet,6,2) = '9-' then
        begin
        fstMon := '0';
        sndMon := '9';
        end else if copy(dateGet,6,2) = '10' then
        begin
        fstMon := '1';
        sndMon := '0';
        end else if copy(dateGet,6,2) = '11' then
        begin
        fstMon := '1';
        sndMon := '1';
        end else if copy(dateGet,6,2) = '12' then
        begin
        fstMon := '1';
        sndMon := '2';
        end;

        fstDay := '2';
        sndDay := '2';

        fstHrs := '0';

        CrimeaStatus := copy(inp, 1, 1);

        if CrimeaStatus = '{' then
        begin
        regCrimeaOn();
        end;

        VolStatus := copy(inp, 349, 6);


        if VolStatus = 'true,' then
        begin
                regVolOn();
        end;

        if VolStatus = 'false' then
        begin
                regVolOff();
        end;

        if VolStatus = 'true,"' then
        begin
                regVolOn();
        end;

        if VolStatus = ':true,' then
        begin
                regVolOn();
        end;

        if VolStatus = 'false,' then
        begin
                regVolOff();
        end;

        VinStatus := copy(inp, 199, 6);

        if VinStatus = ':false' then
        begin
                regVinOff();
        end;

        if VinStatus = '":fals' then
        begin
                regVinOff();
        end;

        if VinStatus = ':true,' then
        begin
                regVinOn();
        end;

        if VinStatus = 'true,"' then
        begin
                regVinOn();
        end;

        if VinStatus = 'false,' then
        begin
                regVinOff();
        end;

        if VinStatus = 'alse,"' then
        begin
                regVinOff();
        end;

        DnStatus := copy(inp, 541, 7);

        if DnStatus = '":true,' then
        begin
                regDnOn();
        end;

        if DnStatus = ':true,"' then
        begin
                regDnOn();
        end;

        if DnStatus = 'true,"c' then
        begin
                regDnOn();
        end;

        if DnStatus = '":false' then
        begin
                regDnOff();
        end;

        if DnStatus = ':false,' then
        begin
                regDnOff();
        end;

        if DnStatus = 'false,"' then
        begin
                regDnOff();
        end;

        DonStatus := copy(inp, 685, 8);

        if DonStatus = 'w":false' then
        begin
                regDonOff();
        end;

        if DonStatus = '":false,' then
        begin
                regDonOff();
        end;

        if DonStatus = ':false,"' then
        begin
                regDonOff();
        end;

        if DonStatus = 'false,"c' then
        begin
                regDonOff();
        end;

        if DonStatus = 'w":true,' then
        begin
                regDonOn();
        end;

        if DonStatus = '":true,"' then
        begin
                regDonOn();
        end;

        if DonStatus = ':true,"c' then
        begin
                regDonOn();
        end;

        if DonStatus = 'true,"ch' then
        begin
                regDonOn();
        end;

        ZhytStatus := copy(inp, 847, 9); // 780 x 960

        if ZhytStatus = 'true,"cha' then
        begin
                regZhytOn();
        end;

        if ZhytStatus = ':true,"ch' then
        begin
                regZhytOn();
        end;

        if ZhytStatus = '":true,"c' then
        begin
                regZhytOn();
        end;

        if ZhytStatus = 'w":true,"' then
        begin
                regZhytOn();
        end;

        if ZhytStatus = 'ow":true,' then
        begin
                regZhytOn();
        end;

        if ZhytStatus = 'ow":false' then
        begin
                regZhytOff();
        end;

        if ZhytStatus = 'w":false,' then
        begin
                regZhytOff();
        end;

        if ZhytStatus = '":false,"' then
        begin
                regZhytOff();
        end;

        if ZhytStatus = ':false,"c' then
        begin
                regZhytOff();
        end;

        if ZhytStatus = 'false,"ch' then
        begin
                regZhytOff();
        end;

        ZakStatus := copy(inp, 1015, 10);

        if ZakStatus = 'false,"cha' then
        begin
                regZakOff();
        end;

        if ZakStatus = 'true,"chan' then
        begin
                regZakOn();
        end;

        if ZakStatus = ':false,"ch' then
        begin
                regZakOff();
        end;

        if ZakStatus = ':true,"cha' then
        begin
                regZakOn();
        end;

        if ZakStatus = '":false,"c' then
        begin
                regZakOff();
        end;

        if ZakStatus = '":true,"ch' then
        begin
                regZakOn();
        end;

        if ZakStatus = 'w":false,"' then
        begin
                regZakOff();
        end;

        if ZakStatus = 'w":true,"c' then
        begin
                regZakOn();
        end;

        if ZakStatus = 'ow":false,' then
        begin
                regZakOff();
        end;

        if ZakStatus = 'ow":true,"' then
        begin
                regZakOn();
        end;

        if ZakStatus = 'now":false' then
        begin
                regZakOff();
        end;

        if ZakStatus = 'now":true,' then
        begin
                regZakOn();
        end;

        IvanoStatus := copy(inp, 1024+340, 12);

        if IvanoStatus = 'false,"chang' then
        begin
                regIvanoOff();
        end;

        if IvanoStatus = 'true,"change' then
        begin
                regIvanoOn();
        end;

        if IvanoStatus = ':false,"chan' then
        begin
                regIvanoOff();
        end;

        if IvanoStatus = ':true,"chang' then
        begin
                regIvanoOn();
        end;

        if IvanoStatus = '":false,"cha' then
        begin
                regIvanoOff();
        end;

        if IvanoStatus = '":true,"chan' then
        begin
                regIvanoOn();
        end;

        if IvanoStatus = 'w":false,"ch' then
        begin
                regIvanoOff();
        end;

        if IvanoStatus = 'w":true,"cha' then
        begin
                regIvanoOn();
        end;

        if IvanoStatus = 'ow":false,"c' then
        begin
                regIvanoOff();
        end;

        if IvanoStatus = 'ow":true,"ch' then
        begin
                regIvanoOn();
        end;

        if IvanoStatus = 'now":false,"' then
        begin
                regIvanoOff();
        end;

        if IvanoStatus = 'now":true,"c' then
        begin
                regIvanoOn();
        end;

        if IvanoStatus = 'tnow":false,' then
        begin
                regIvanoOff();
        end;

        if IvanoStatus = 'tnow":true,"' then
        begin
                regIvanoOn();
        end;

        if IvanoStatus = 'rtnow":false' then
        begin
                regIvanoOff();
        end;

        if IvanoStatus = 'rtnow":true,' then
        begin
                regIvanoOn();
        end;

        KyivStatus := copy(inp, 1024+484, 13);

        if KyivStatus = 'ertnow":false' then
        begin
                regKyivOff();
        end;

        if KyivStatus = 'ertnow":true,' then
        begin
                regKyivOn();
        end;

        if KyivStatus = 'rtnow":false,' then
        begin
                regKyivOff();
        end;

        if KyivStatus = 'rtnow":true,"' then
        begin
                regKyivOn();
        end;

        if KyivStatus = 'tnow":false,"' then
        begin
                regKyivOff();
        end;

        if KyivStatus = 'tnow":true,"c' then
        begin
                regKyivOn();
        end;

        if KyivStatus = 'now":false,"c' then
        begin
                regKyivOff();
        end;

        if KyivStatus = 'now":true,"ch' then
        begin
                regKyivOn();
        end;

        if KyivStatus = 'ow":false,"ch' then
        begin
                regKyivOff();
        end;

        if KyivStatus = 'ow":true,"cha' then
        begin
                regKyivOn();
        end;

        if KyivStatus = 'w":false,"cha' then
        begin
                regKyivOff();
        end;

        if KyivStatus = 'w":true,"chan' then
        begin
                regKyivOn();
        end;

        if KyivStatus = '":false,"chan' then
        begin
                regKyivOff();
        end;

        if KyivStatus = '":true,"chang' then
        begin
                regKyivOn();
        end;

        if KyivStatus = ':false,"chang' then
        begin
                regKyivOff();
        end;

        if KyivStatus = ':true,"change' then
        begin
                regKyivOn();
        end;

        if KyivStatus = 'false,"change' then
        begin
                regKyivOff();
        end;

        if KyivStatus = 'true,"changed' then
        begin
                regKyivOn();
        end;

        KiroStatus := copy(inp, 1024+664, 14);

        if KiroStatus = 'false,"changed' then
        begin
                regKyroOff();
        end;

        if KiroStatus = 'true,"changed"' then
        begin
                regKyroOn();
        end;

        if KiroStatus = ':false,"change' then
        begin
                regKyroOff();
        end;

        if KiroStatus = ':true,"changed' then
        begin
                regKyroOn();
        end;

        if KiroStatus = '":false,"chang' then
        begin
                regKyroOff();
        end;

        if KiroStatus = '":true,"change' then
        begin
                regKyroOn();
        end;

        if KiroStatus = 'w":false,"chan' then
        begin
                regKyroOff();
        end;

        if KiroStatus = 'w":true,"chang' then
        begin
                regKyroOn();
        end;

        if KiroStatus = 'ow":false,"cha' then
        begin
                regKyroOff();
        end;

        if KiroStatus = 'ow":true,"chan' then
        begin
                regKyroOn();
        end;

        if KiroStatus = 'now":false,"ch' then
        begin
                regKyroOff();
        end;

        if KiroStatus = 'now":true,"cha' then
        begin
                regKyroOn();
        end;

        if KiroStatus = 'tnow":false,"c' then
        begin
                regKyroOff();
        end;

        if KiroStatus = 'tnow":true,"ch' then
        begin
                regKyroOn();
        end;

        if KiroStatus = 'rtnow":false,"' then
        begin
                regKyroOff();
        end;

        if KiroStatus = 'rtnow":true,"c' then
        begin
                regKyroOn();
        end;

        if KiroStatus = 'ertnow":false,' then
        begin
                regKyroOff();
        end;

        if KiroStatus = 'ertnow":true,"' then
        begin
                regKyroOn();
        end;

        if KiroStatus = 'lertnow":false' then
        begin
                regKyroOff();
        end;

        if KiroStatus = 'lertnow":true,' then
        begin
                regKyroOn();
        end;

        LuhStatus := copy(inp, 1024+814, 15);

        if LuhStatus = 'alertnow":false' then
        begin
                regLuhOff();
        end;

        if LuhStatus = 'alertnow":true,' then
        begin
                regLuhOn();
        end;

        if LuhStatus = 'lertnow":false,' then
        begin
                regLuhOff();
        end;

        if LuhStatus = 'lertnow":true,"' then
        begin
                regLuhOn();
        end;

        if LuhStatus = 'ertnow":false,"' then
        begin
                regLuhOff();
        end;

        if LuhStatus = 'ertnow":true,"c' then
        begin
                regLuhOn();
        end;

        if LuhStatus = 'rtnow":false,"c' then
        begin
                regLuhOff();
        end;

        if LuhStatus = 'rtnow":true,"ch' then
        begin
                regLuhOn();
        end;

        if LuhStatus = 'tnow":false,"ch' then
        begin
                regLuhOff();
        end;

        if LuhStatus = 'tnow":true,"cha' then
        begin
                regLuhOn();
        end;

        if LuhStatus = 'now":false,"cha' then
        begin
                regLuhOff();
        end;

        if LuhStatus = 'now":true,"chan' then
        begin
                regLuhOn();
        end;

        if LuhStatus = 'ow":false,"chan' then
        begin
                regLuhOff();
        end;

        if LuhStatus = 'ow":true,"chang' then
        begin
                regLuhOn();
        end;

        if LuhStatus = 'w":false,"chang' then
        begin
                regLuhOff();
        end;

        if LuhStatus = 'w":true,"change' then
        begin
                regLuhOn();
        end;

        if LuhStatus = '":false,"change' then
        begin
                regLuhOff();
        end;

        if LuhStatus = '":true,"changed' then
        begin
                regLuhOn();
        end;

        if LuhStatus = ':false,"changed' then
        begin
                regLuhOff();
        end;

        if LuhStatus = ':true,"changed"' then
        begin
                regLuhOn();
        end;

        if LuhStatus = 'false,"changed"' then
        begin
                regLuhOff();
        end;

        if LuhStatus = 'true,"changed":' then
        begin
                regLuhOn();
        end;

        LvivStatus := copy(inp, 1024+964, 16);

        if LvivStatus = 'false,"changed":' then
        begin
                regLvivOff();
        end;

        if LvivStatus = 'true,"changed":"' then
        begin
                regLvivOn();
        end;

        if LvivStatus = ':false,"changed"' then
        begin
                regLvivOff();
        end;

        if LvivStatus = ':true,"changed":' then
        begin
                regLvivOn();
        end;

        if LvivStatus = '":false,"changed' then
        begin
                regLvivOff();
        end;

        if LvivStatus = '":true,"changed"' then
        begin
                regLvivOn();
        end;

        if LvivStatus = 'w":false,"change' then
        begin
                regLvivOff();
        end;

        if LvivStatus = 'w":true,"changed' then
        begin
                regLvivOn();
        end;

        if LvivStatus = 'ow":false,"chang' then
        begin
                regLvivOff();
        end;

        if LvivStatus = 'ow":true,"change' then
        begin
                regLvivOn();
        end;

        if LvivStatus = 'now":false,"chan' then
        begin
                regLvivOff();
        end;

        if LvivStatus = 'now":true,"chang' then
        begin
                regLvivOn();
        end;

        if LvivStatus = 'tnow":false,"cha' then
        begin
                regLvivOff();
        end;

        if LvivStatus = 'tnow":true,"chan' then
        begin
                regLvivOn();
        end;

        if LvivStatus = 'rtnow":false,"ch' then
        begin
                regLvivOff();
        end;

        if LvivStatus = 'rtnow":true,"cha' then
        begin
                regLvivOn();
        end;

        if LvivStatus = 'ertnow":false,"c' then
        begin
                regLvivOff();
        end;

        if LvivStatus = 'ertnow":true,"ch' then
        begin
                regLvivOn();
        end;

        if LvivStatus = 'lertnow":false,"' then
        begin
                regLvivOff();
        end;

        if LvivStatus = 'lertnow":true,"c' then
        begin
                regLvivOn();
        end;

        if LvivStatus = 'alertnow":false,' then
        begin
                regLvivOff();
        end;

        if LvivStatus = 'alertnow":true,"' then
        begin
                regLvivOn();
        end;

        if LvivStatus = '"alertnow":false' then
        begin
                regLvivOff();
        end;

        if LvivStatus = '"alertnow":true,' then
        begin
                regLvivOn();
        end;

        MykStatus := copy(inp, 2048+108, 17);

        if MykStatus = '{"alertnow":false' then
        begin
                regMykOff();
        end;

        if MykStatus = '{"alertnow":true,' then
        begin
                Form1.regMyk.Visible := true;
                Form1.statusMyk.Visible := true;
        end;

        if MykStatus = '"alertnow":false,' then
        begin
                regMykOff();
        end;

        if MykStatus = '"alertnow":true,"' then
        begin
                regMykOn();
        end;

        if MykStatus = 'alertnow":false,"' then
        begin
                regMykOff();
        end;

        if MykStatus = 'alertnow":true,"c' then
        begin
                regMykOn();
        end;

        if MykStatus = 'lertnow":false,"c' then
        begin
                regMykOff();
        end;

        if MykStatus = 'lertnow":true,"ch' then
        begin
                regMykOn();
        end;

        if MykStatus = 'ertnow":false,"ch' then
        begin
                regMykOff();
        end;

        if MykStatus = 'ertnow":true,"cha' then
        begin
                regMykOn();
        end;

        if MykStatus = 'rtnow":false,"cha' then
        begin
                regMykOff();
        end;

        if MykStatus = 'rtnow":true,"chan' then
        begin
                regMykOn();
        end;

        if MykStatus = 'tnow":false,"chan' then
        begin
                regMykOff();
        end;

        if MykStatus = 'tnow":true,"chang' then
        begin
                regMykOn();
        end;

        if MykStatus = 'now":false,"chang' then
        begin
                regMykOff();
        end;

        if MykStatus = 'now":true,"change' then
        begin
                regMykOn();
        end;

        if MykStatus = 'ow":false,"change' then
        begin
                regMykOff();
        end;

        if MykStatus = 'ow":true,"changed' then
        begin
                regMykOn();
        end;

        if MykStatus = 'w":false,"changed' then
        begin
                regMykOff();
        end;

        if MykStatus = 'w":true,"changed"' then
        begin
                regMykOn();
        end;

        if MykStatus = '":false,"changed"' then
        begin
                regMykOff();
        end;

        if MykStatus = '":true,"changed":' then
        begin
                regMykOn();
        end;

        if MykStatus = ':false,"changed":' then
        begin
                regMykOff();
        end;

        if MykStatus = ':true,"changed":"' then
        begin
                regMykOn();
        end;

        if MykStatus = 'false,"changed":"' then
        begin
                regMykOff();
        end;

        if MykStatus = 'true,"changed":"'+fstYear then
        begin
                regMykOn();
        end;

        OdesStatus := copy(inp, 2048+246, 18);

        if OdesStatus = 'false,"changed":"'+fstYear then
        begin
                regOdesOff();
        end;

        if OdesStatus = 'true,"changed":"'+fstYear+sndYear then
        begin
                regOdesOn();
        end;

        if OdesStatus = ':false,"changed":"' then
        begin
                regOdesOff();
        end;

        if OdesStatus = ':true,"changed":"'+fstYear then
        begin
                regOdesOn();
        end;

        if OdesStatus = '":false,"changed":' then
        begin
                regOdesOff();
        end;

        if OdesStatus = '":true,"changed":"' then
        begin
                regOdesOn();
        end;

        if OdesStatus = 'w":false,"changed"' then
        begin
                regOdesOff();
        end;

        if OdesStatus = 'w":true,"changed":' then
        begin
                regOdesOn();
        end;

        if OdesStatus = 'ow":false,"changed' then
        begin
                regOdesOff();
        end;

        if OdesStatus = 'ow":true,"changed"' then
        begin
                regOdesOn();
        end;

        if OdesStatus = 'now":false,"change' then
        begin
                regOdesOff();
        end;

        if OdesStatus = 'now":true,"changed' then
        begin
                regOdesOn();
        end;

        if OdesStatus = 'tnow":false,"chang' then
        begin
                regOdesOff();
        end;

        if OdesStatus = 'tnow":true,"change' then
        begin
                regOdesOn();
        end;

        if OdesStatus = 'rtnow":false,"chan' then
        begin
                regOdesOff();
        end;

        if OdesStatus = 'rtnow":true,"chang' then
        begin
                regOdesOn();
        end;

        if OdesStatus = 'ertnow":false,"cha' then
        begin
                regOdesOff();
        end;

        if OdesStatus = 'ertnow":true,"chan' then
        begin
                regOdesOn();
        end;

        if OdesStatus = 'lertnow":false,"ch' then
        begin
                regOdesOff();
        end;

        if OdesStatus = 'lertnow":true,"cha' then
        begin
                regOdesOn();
        end;

        if OdesStatus = 'alertnow":false,"c' then
        begin
                regOdesOff();
        end;

        if OdesStatus = 'alertnow":true,"ch' then
        begin
                regOdesOn();
        end;

        if OdesStatus = '"alertnow":false,"' then
        begin
                regOdesOff();
        end;

        if OdesStatus = '"alertnow":true,"c' then
        begin
                regOdesOn();
        end;

        if OdesStatus = '{"alertnow":false,' then
        begin
                regOdesOff();
        end;

        if OdesStatus = '{"alertnow":true,"' then
        begin
                regOdesOn();
        end;

        if OdesStatus = ':{"alertnow":false' then
        begin
                regOdesOff();
        end;

        if OdesStatus = ':{"alertnow":true,' then
        begin
                regOdesOn();
        end;

        PoltStatus := copy(inp, 2048+402, 19);

        if PoltStatus = '":{"alertnow":false' then
        begin
                regPoltOff();
        end;

        if PoltStatus = '":{"alertnow":true,' then
        begin
                regPoltOn();
        end;

        if PoltStatus = ':{"alertnow":false,' then
        begin
                regPoltOff();
        end;

        if PoltStatus = ':{"alertnow":true,"' then
        begin
                regPoltOn();
        end;

        if PoltStatus = '{"alertnow":false,"' then
        begin
                regPoltOff();
        end;

        if PoltStatus = '{"alertnow":true,"c' then
        begin
                regPoltOn();
        end;

        if PoltStatus = '"alertnow":false,"c' then
        begin
                regPoltOff();
        end;

        if PoltStatus = '"alertnow":true,"ch' then
        begin
                regPoltOn();
        end;

        if PoltStatus = 'alertnow":false,"ch' then
        begin
                regPoltOff();
        end;

        if PoltStatus = 'alertnow":true,"cha' then
        begin
                regPoltOn();
        end;

        if PoltStatus = 'lertnow":false,"cha' then
        begin
                regPoltOff();
        end;

        if PoltStatus = 'lertnow":true,"chan' then
        begin
                regPoltOn();
        end;

        if PoltStatus = 'ertnow":false,"chan' then
        begin
                regPoltOff();
        end;

        if PoltStatus = 'ertnow":true,"chang' then
        begin
                regPoltOn();
        end;

        if PoltStatus = 'rtnow":false,"chang' then
        begin
                regPoltOff();
        end;

        if PoltStatus = 'rtnow":true,"change' then
        begin
                regPoltOn();
        end;

        if PoltStatus = 'tnow":false,"change' then
        begin
                regPoltOff();
        end;

        if PoltStatus = 'tnow":true,"changed' then
        begin
                regPoltOn();
        end;

        if PoltStatus = 'now":false,"changed' then
        begin
                regPoltOff();
        end;

        if PoltStatus = 'now":true,"changed"' then
        begin
                regPoltOn();
        end;

        if PoltStatus = 'ow":false,"changed"' then
        begin
                regPoltOff();
        end;

        if PoltStatus = 'ow":true,"changed":' then
        begin
                regPoltOn();
        end;

        if PoltStatus = 'w":false,"changed":' then
        begin
                regPoltOff();
        end;

        if PoltStatus = 'w":true,"changed":"' then
        begin
                regPoltOn();
        end;

        if PoltStatus = '":false,"changed":"' then
        begin
                regPoltOff();
        end;

        if PoltStatus = '":true,"changed":"'+fstYear then
        begin
                regPoltOn();
        end;

        if PoltStatus = ':false,"changed":"'+fstYear then
        begin
                regPoltOff();
        end;

        if PoltStatus = ':true,"changed":"'+fstYear+sndYear then
        begin
                regPoltOn();
        end;

        if PoltStatus = 'false,"changed":"'+fstYear+sndYear then
        begin
                regPoltOff();
        end;

        if PoltStatus = 'true,"changed":"'+fstYear+sndYear+trdYear then
        begin
                regPoltOn();
        end;

        RivStatus := copy(inp, 2048+558, 20);

        if RivStatus = 'false,"changed":"'+fstYear+sndYear+trdYear then
        begin
                regRivnOff();
        end;

        if RivStatus = 'true,"changed":"'+fstYear+sndYear+trdYear+frtYear then
        begin
                regRivnOn();
        end;

        if RivStatus = ':false,"changed":"'+fstYear+sndYear then
        begin
                regRivnOff();
        end;

        if RivStatus = ':true,"changed":"'+fstYear+sndYear+trdYear then
        begin
                regRivnOn();
        end;

        if RivStatus = '":false,"changed":"'+fstYear then
        begin
                regRivnOff();
        end;

        if RivStatus = '":true,"changed":"'+fstYear+sndYear then
        begin
                regRivnOn();
        end;

        if RivStatus = 'w":false,"changed":"' then
        begin
                regRivnOff();
        end;

        if RivStatus = 'w":true,"changed":"'+fstYear then
        begin
                regRivnOn();
        end;

        if RivStatus = 'ow":false,"changed":' then
        begin
                regRivnOff();
        end;

        if RivStatus = 'ow":true,"changed":"' then
        begin
                regRivnOn();
        end;

        if RivStatus = 'now":false,"changed"' then
        begin
                regRivnOff();
        end;

        if RivStatus = 'now":true,"changed":' then
        begin
                regRivnOn();
        end;

        if RivStatus = 'tnow":false,"changed' then
        begin
                regRivnOff();
        end;

        if RivStatus = 'tnow":true,"changed"' then
        begin
                regRivnOn();
        end;

        if RivStatus = 'rtnow":false,"change' then
        begin
                regRivnOff();
        end;

        if RivStatus = 'rtnow":true,"changed' then
        begin
                regRivnOn();
        end;

        if RivStatus = 'ertnow":false,"chang' then
        begin
                regRivnOff();
        end;

        if RivStatus = 'ertnow":true,"change' then
        begin
                regRivnOn();
        end;

        if RivStatus = 'lertnow":false,"chan' then
        begin
                regRivnOff();
        end;

        if RivStatus = 'lertnow":true,"chang' then
        begin
                regRivnOn();
        end;

        if RivStatus = 'alertnow":false,"cha' then
        begin
                regRivnOff();
        end;

        if RivStatus = 'alertnow":true,"chan' then
        begin
                regRivnOn();
        end;

        if RivStatus = '"alertnow":false,"ch' then
        begin
                regRivnOff();
        end;

        if RivStatus = '"alertnow":true,"cha' then
        begin
                regRivnOn();
        end;

        if RivStatus = '{"alertnow":false,"c' then
        begin
                regRivnOff();
        end;

        if RivStatus = '{"alertnow":true,"ch' then
        begin
                regRivnOn();
        end;

        if RivStatus = ':{"alertnow":false,"' then
        begin
                regRivnOff();
        end;

        if RivStatus = ':{"alertnow":true,"c' then
        begin
                regRivnOn();
        end;

        if RivStatus = '":{"alertnow":false,' then
        begin
                regRivnOff();
        end;

        if RivStatus = '":{"alertnow":true,"' then
        begin
                regRivnOn();
        end;

        if RivStatus = 'c":{"alertnow":false' then
        begin
                regRivnOff();
        end;

        if RivStatus = 'c":{"alertnow":true,' then
        begin
                regRivnOn();
        end;

        SumStatus := copy(inp, 2048+696, 21);

        if SumStatus = '4c":{"alertnow":false' then
        begin
                regSumOff();
        end;

        if SumStatus = '4c":{"alertnow":true,' then
        begin
                regSumOn();
        end;

        if SumStatus = 'c":{"alertnow":false,' then
        begin
                regSumOff();
        end;

        if SumStatus = 'c":{"alertnow":true,"' then
        begin
                regSumOn();
        end;

        if SumStatus = '":{"alertnow":false,"' then
        begin
                regSumOff();
        end;

        if SumStatus = '":{"alertnow":true,"c' then
        begin
                regSumOn();
        end;

        if SumStatus = ':{"alertnow":false,"c' then
        begin
                regSumOff();
        end;

        if SumStatus = ':{"alertnow":true,"ch' then
        begin
                regSumOn();
        end;

        if SumStatus = '{"alertnow":false,"ch' then
        begin
                regSumOff();
        end;

        if SumStatus = '{"alertnow":true,"cha' then
        begin
                regSumOn();
        end;

        if SumStatus = '"alertnow":false,"cha' then
        begin
                regSumOff();
        end;

        if SumStatus = '"alertnow":true,"chan' then
        begin
                regSumOn();
        end;

        if SumStatus = 'alertnow":false,"chan' then
        begin
                regSumOff();
        end;

        if SumStatus = 'alertnow":true,"chang' then
        begin
                regSumOn();
        end;

        if SumStatus = 'lertnow":false,"chang' then
        begin
                regSumOff();
        end;

        if SumStatus = 'lertnow":true,"change' then
        begin
                regSumOn();
        end;

        if SumStatus = 'ertnow":false,"change' then
        begin
                regSumOff();
        end;

        if SumStatus = 'ertnow":true,"changed' then
        begin
                regSumOn();
        end;

        if SumStatus = 'rtnow":false,"changed' then
        begin
                regSumOff();
        end;

        if SumStatus = 'rtnow":true,"changed"' then
        begin
                regSumOn();
        end;

        if SumStatus = 'tnow":false,"changed"' then
        begin
                regSumOff();
        end;

        if SumStatus = 'tnow":true,"changed":' then
        begin
                regSumOn();
        end;

        if SumStatus = 'now":false,"changed":' then
        begin
                regSumOff();
        end;

        if SumStatus = 'now":true,"changed":"' then
        begin
                regSumOn();
        end;

        if SumStatus = 'ow":false,"changed":"' then
        begin
                regSumOff();
        end;

        if SumStatus = 'ow":true,"changed":"'+fstYear then
        begin
                regSumOn();
        end;

        if SumStatus = 'w":false,"changed":"'+fstYear then
        begin
                regSumOff();
        end;

        if SumStatus = 'w":true,"changed":"'+fstYear+sndYear then
        begin
                regSumOn();
        end;

        if SumStatus = '":false,"changed":"'+fstYear+sndYear then
        begin
                regSumOff();
        end;

        if SumStatus = '":true,"changed":"'+fstYear+sndYear+trdYear then
        begin
                regSumOn();
        end;

        if SumStatus = '"false,"changed":"'+fstYear+sndYear+trdYear then
        begin
                regSumOff();
        end;

        if SumStatus = '"true,"changed":"'+fstYear+sndYear+trdYear+frtYear then
        begin
                regSumOn();
        end;

        if SumStatus = 'false,"changed":"'+fstYear+sndYear+trdYear+frtYear then
        begin
                regSumOff();
        end;

        if SumStatus = 'true,"changed":"'+fstYear+sndYear+trdYear+frtYear+'-' then
        begin
                regSumOn();
        end;

        TernStatus := copy(inp, 2048+870, 22);

        if TernStatus = 'false,"changed":"'+fstYear+sndYear+trdYear+frtYear+'-' then
        begin
                regTernOff();
        end;

        if TernStatus = 'true,"changed":"'+fstYear+sndYear+trdYear+frtYear+'-'+fstMon then
        begin
                regTernOn();
        end;

        if TernStatus = ':false,"changed":"'+fstYear+sndYear+trdYear+frtYear then
        begin
                regTernOff();
        end;

        if TernStatus = ':true,"changed":"'+fstYear+sndYear+trdYear+frtYear+'-' then
        begin
                regTernOn();
        end;

        if TernStatus = '":false,"changed":"'+fstYear+sndYear+trdYear then
        begin
                regTernOff();
        end;

        if TernStatus = '":true,"changed":"'+fstYear+sndYear+trdYear+frtYear then
        begin
                regTernOn();
        end;

        if TernStatus = 'w":false,"changed":"'+fstYear+sndYear then
        begin
                regTernOff();
        end;

        if TernStatus = 'w":true,"changed":"'+fstYear+sndYear+trdYear then
        begin
                regTernOn();
        end;

        if TernStatus = 'ow":false,"changed":"'+fstYear then
        begin
                regTernOff();
        end;

        if TernStatus = 'ow":true,"changed":"'+fstYear+sndYear then
        begin
                regTernOn();
        end;

        if TernStatus = 'now":false,"changed":"' then
        begin
                regTernOff();
        end;

        if TernStatus = 'now":true,"changed":"'+fstYear then
        begin
                regTernOn();
        end;

        if TernStatus = 'tnow":false,"changed":' then
        begin
                regTernOff();
        end;

        if TernStatus = 'tnow":true,"changed":"' then
        begin
                regTernOn();
        end;

        if TernStatus = 'rtnow":false,"changed"' then
        begin
                regTernOff();
        end;

        if TernStatus = 'rtnow":true,"changed":' then
        begin
                regTernOn();
        end;

        if TernStatus = 'ertnow":false,"changed' then
        begin
                regTernOff();
        end;

        if TernStatus = 'ertnow":true,"changed"' then
        begin
                regTernOn();
        end;

        if TernStatus = 'lertnow":false,"change' then
        begin
                regTernOff();
        end;

        if TernStatus = 'lertnow":true,"changed'then
        begin
                regTernOn();
        end;

        if TernStatus = 'alertnow":false,"chang' then
        begin
                regTernOff();
        end;

        if TernStatus = 'alertnow":true,"change'then
        begin
                regTernOn();
        end;

        if TernStatus = '"alertnow":false,"chan' then
        begin
                regTernOff();
        end;

        if TernStatus = '"alertnow":true,"chang' then
        begin
                regTernOn();
        end;

        if TernStatus = '{"alertnow":false,"cha' then
        begin
                regTernOff();
        end;

        if TernStatus = '{"alertnow":true,"chan' then
        begin
                regTernOn();
        end;

        if TernStatus = ':{"alertnow":false,"ch' then
        begin
                regTernOff();
        end;

        if TernStatus = ':{"alertnow":true,"cha' then
        begin
                regTernOn();
        end;

        if TernStatus = '":{"alertnow":false,"c' then
        begin
                regTernOff();
        end;

        if TernStatus = '":{"alertnow":true,"ch' then
        begin
                regTernOn();
        end;

        if TernStatus = 'c":{"alertnow":false,"' then
        begin
                regTernOff();
        end;

        if TernStatus = 'c":{"alertnow":true,"c' then
        begin
                regTernOn();
        end;

        if TernStatus = '4c":{"alertnow":false,' then
        begin
                regTernOff();
        end;

        if TernStatus = '4c":{"alertnow":true,"' then
        begin
                regTernOn();
        end;

        if TernStatus = '44c":{"alertnow":false' then
        begin
                regTernOff();
        end;

        if TernStatus = '44c":{"alertnow":true,' then
        begin
                regTernOn();
        end;

        KhaStatus := copy(inp, 3072+2, 23);

        if KhaStatus = '044c":{"alertnow":false' then
        begin
                regKhaOff();
        end;

        if KhaStatus = '044c":{"alertnow":true,' then
        begin
                regKhaOn();
        end;

        if KhaStatus = '44c":{"alertnow":false,' then
        begin
                regKhaOff();
        end;

        if KhaStatus = '44c":{"alertnow":true,"' then
        begin
                regKhaOn();
        end;

        if KhaStatus = '4c":{"alertnow":false,"' then
        begin
                regKhaOff();
        end;

        if KhaStatus = '4c":{"alertnow":true,"c' then
        begin
                regKhaOn();
        end;

        if KhaStatus = 'c":{"alertnow":false,"c' then
        begin
                regKhaOff();
        end;

        if KhaStatus = 'c":{"alertnow":true,"ch' then
        begin
                regKhaOn();
        end;

        if KhaStatus = '":{"alertnow":false,"ch' then
        begin
                regKhaOff();
        end;

        if KhaStatus = '":{"alertnow":true,"cha' then
        begin
                regKhaOn();
        end;

        if KhaStatus = ':{"alertnow":false,"cha' then
        begin
                regKhaOff();
        end;

        if KhaStatus = ':{"alertnow":true,"chan' then
        begin
                regKhaOn();
        end;

        if KhaStatus = '{"alertnow":false,"chan' then
        begin
                regKhaOff();
        end;

        if KhaStatus = '{"alertnow":true,"chang' then
        begin
                regKhaOn();
        end;

        if KhaStatus = '"alertnow":false,"chang' then
        begin
                regKhaOff();
        end;

        if KhaStatus = '"alertnow":true,"change' then
        begin
                regKhaOn();
        end;

        if KhaStatus = 'alertnow":false,"change' then
        begin
                regKhaOff();
        end;

        if KhaStatus = 'alertnow":true,"changed' then
        begin
                regKhaOn();
        end;

        if KhaStatus = 'lertnow":false,"changed' then
        begin
                regKhaOff();
        end;

        if KhaStatus = 'lertnow":true,"changed"' then
        begin
                regKhaOn();
        end;

        if KhaStatus = 'ertnow":false,"changed"' then
        begin
                regKhaOff();
        end;

        if KhaStatus = 'ertnow":true,"changed":' then
        begin
                regKhaOn();
        end;

        if KhaStatus = 'rtnow":false,"changed":' then
        begin
                regKhaOff();
        end;

        if KhaStatus = 'rtnow":true,"changed":"' then
        begin
                regKhaOn();
        end;

        if KhaStatus = 'tnow":false,"changed":"' then
        begin
                regKhaOff();
        end;

        if KhaStatus = 'tnow":true,"changed":"'+fstYear then
        begin
                regKhaOn();
        end;

        if KhaStatus = 'now":false,"changed":"'+fstYear then
        begin
                regKhaOff();
        end;

        if KhaStatus = 'now":true,"changed":"'+fstYear+sndYear then
        begin
                regKhaOn();
        end;

        if KhaStatus = 'ow":false,"changed":"'+fstYear+sndYear then
        begin
                regKhaOff();
        end;

        if KhaStatus = 'ow":true,"changed":"'+fstYear+sndYear+trdYear then
        begin
                regKhaOn();
        end;

        if KhaStatus = 'w":false,"changed":"'+fstYear+sndYear+trdYear then
        begin
                regKhaOff();
        end;

        if KhaStatus = 'w":true,"changed":"'+fstYear+sndYear+trdYear+frtYear then
        begin
                regKhaOn();
        end;

        if KhaStatus = '":false,"changed":"'+fstYear+sndYear+trdYear+frtYear then
        begin
                regKhaOff();
        end;

        if KhaStatus = '":true,"changed":"'+fstYear+sndYear+trdYear+frtYear+'-' then
        begin
                regKhaOn();
        end;

        if KhaStatus = ':false,"changed":"'+fstYear+sndYear+trdYear+frtYear+'-' then
        begin
                regKhaOff();
        end;

        if KhaStatus = ':true,"changed":"'+fstYear+sndYear+trdYear+frtYear+'-'+fstMon then
        begin
                regKhaOn();
        end;

        if KhaStatus = 'false,"changed":"'+fstYear+sndYear+trdYear+frtYear+'-'+fstMon then
        begin
                regKhaOff();
        end;

        if KhaStatus = 'true,"changed":"'+fstYear+sndYear+trdYear+frtYear+'-'+fstMon+sndMon then
        begin
                regKhaOn();
        end;

        KheStatus := copy(inp, 3072+158, 24);

        if KheStatus = 'false,"changed":"'+fstYear+sndYear+trdYear+frtYear+'-'+fstMon+sndMon then
        begin
                regKherOff();
        end;

        if KheStatus = 'true,"changed":"'+fstYear+sndYear+trdYear+frtYear+'-'+fstMon+sndMon+'-' then
        begin
                regKherOn();
        end;

        if KheStatus = ':false,"changed":"'+fstYear+sndYear+trdYear+frtYear+'-'+fstMon then
        begin
                regKherOff();
        end;

        if KheStatus = ':true,"changed":"'+fstYear+sndYear+trdYear+frtYear+'-'+fstMon+sndMon then
        begin
                regKherOn();
        end;

        if KheStatus = '":false,"changed":"'+fstYear+sndYear+trdYear+frtYear+'-' then
        begin
                regKherOff();
        end;

        if KheStatus = '":true,"changed":"'+fstYear+sndYear+trdYear+frtYear+'-'+fstMon then
        begin
                regKherOn();
        end;

        if KheStatus = 'w":false,"changed":"'+fstYear+sndYear+trdYear+frtYear then
        begin
                regKherOff();
        end;

        if KheStatus = 'w":true,"changed":"'+fstYear+sndYear+trdYear+frtYear+'-' then
        begin
                regKherOn();
        end;

        if KheStatus = 'ow":false,"changed":"'+fstYear+sndYear+trdYear then
        begin
                regKherOff();
        end;

        if KheStatus = 'ow":true,"changed":"'+fstYear+sndYear+trdYear+frtYear then
        begin
                regKherOn();
        end;

        if KheStatus = 'now":false,"changed":"'+fstYear+sndYear then
        begin
                regKherOff();
        end;

        if KheStatus = 'now":true,"changed":"'+fstYear+sndYear+trdYear then
        begin
                regKherOn();
        end;

        if KheStatus = 'tnow":false,"changed":"'+fstYear then
        begin
                regKherOff();
        end;

        if KheStatus = 'tnow":true,"changed":"'+fstYear+sndYear then
        begin
                regKherOn();
        end;

        if KheStatus = 'rtnow":false,"changed":"' then
        begin
                regKherOff();
        end;

        if KheStatus = 'rtnow":true,"changed":"'+fstYear then
        begin
                regKherOn();
        end;

        if KheStatus = 'ertnow":false,"changed":' then
        begin
                regKherOff();
        end;

        if KheStatus = 'ertnow":true,"changed":"' then
        begin
                regKherOn();
        end;

        if KheStatus = 'lertnow":false,"changed"' then
        begin
                regKherOff();
        end;

        if KheStatus = 'lertnow":true,"changed":' then
        begin
                regKherOn();
        end;

        if KheStatus = 'alertnow":false,"changed' then
        begin
                regKherOff();
        end;

        if KheStatus = 'alertnow":true,"changed"' then
        begin
                regKherOn();
        end;

        if KheStatus = '"alertnow":false,"change' then
        begin
                regKherOff();
        end;

        if KheStatus = '"alertnow":true,"changed' then
        begin
                regKherOn();
        end;

        if KheStatus = '{"alertnow":false,"chang' then
        begin
                regKherOff();
        end;

        if KheStatus = '{"alertnow":true,"change' then
        begin
                regKherOn();
        end;

        if KheStatus = ':{"alertnow":false,"chan' then
        begin
                regKherOff();
        end;

        if KheStatus = ':{"alertnow":true,"chang' then
        begin
                regKherOn();
        end;

        if KheStatus = '":{"alertnow":false,"cha' then
        begin
                regKherOff();
        end;

        if KheStatus = '":{"alertnow":true,"chan' then
        begin
                regKherOn();
        end;

        if KheStatus = 'c":{"alertnow":false,"ch' then
        begin
                regKherOff();
        end;

        if KheStatus = 'c":{"alertnow":true,"cha' then
        begin
                regKherOn();
        end;

        if KheStatus = '4c":{"alertnow":false,"c' then
        begin
                regKherOff();
        end;

        if KheStatus = '4c":{"alertnow":true,"ch' then
        begin
                regKherOn();
        end;

        if KheStatus = '44c":{"alertnow":false,"' then
        begin
                regKherOff();
        end;

        if KheStatus = '44c":{"alertnow":true,"c' then
        begin
                regKherOn();
        end;

        if KheStatus = '044c":{"alertnow":false,' then
        begin
                regKherOff();
        end;

        if KheStatus = '044c":{"alertnow":true,"' then
        begin
                regKherOn();
        end;

        if KheStatus = 'u044c":{"alertnow":false' then
        begin
                regKherOff();
        end;

        if KheStatus = 'u044c":{"alertnow":true,' then
        begin
                regKherOn();
        end;

        KhmelnStatus := copy(inp, 3072+320, 25);

        if KhmelnStatus = '\u044c":{"alertnow":false' then
        begin
                regChmelnOff();
        end;

        if KhmelnStatus = '\u044c":{"alertnow":true,' then
        begin
                regChmelnOn();
        end;

        if KhmelnStatus = 'u044c":{"alertnow":false,' then
        begin
                regChmelnOff();
        end;

        if KhmelnStatus = 'u044c":{"alertnow":true,"' then
        begin
                regChmelnOn();
        end;

        if KhmelnStatus = '044c":{"alertnow":false,"' then
        begin
                regChmelnOff();
        end;

        if KhmelnStatus = '044c":{"alertnow":true,"c' then
        begin
                regChmelnOn();
        end;

        if KhmelnStatus = '44c":{"alertnow":false,"c' then
        begin
                regChmelnOff();
        end;

        if KhmelnStatus = '44c":{"alertnow":true,"ch' then
        begin
                regChmelnOn();
        end;

        if KhmelnStatus = '4c":{"alertnow":false,"ch' then
        begin
                regChmelnOff();
        end;

        if KhmelnStatus = '4c":{"alertnow":true,"cha' then
        begin
                regChmelnOn();
        end;

        if KhmelnStatus = 'c":{"alertnow":false,"cha' then
        begin
                regChmelnOff();
        end;

        if KhmelnStatus = 'c":{"alertnow":true,"chan' then
        begin
                regChmelnOn();
        end;

        if KhmelnStatus = '":{"alertnow":false,"chan' then
        begin
                regChmelnOff();
        end;

        if KhmelnStatus = '":{"alertnow":true,"chang' then
        begin
                regChmelnOn();
        end;

        if KhmelnStatus = ':{"alertnow":false,"chang' then
        begin
                regChmelnOff();
        end;

        if KhmelnStatus = ':{"alertnow":true,"change' then
        begin
                regChmelnOn();
        end;

        if KhmelnStatus = '{"alertnow":false,"change' then
        begin
                regChmelnOff();
        end;

        if KhmelnStatus = '{"alertnow":true,"changed' then
        begin
                regChmelnOn();
        end;

        if KhmelnStatus = '"alertnow":false,"changed' then
        begin
                regChmelnOff();
        end;

        if KhmelnStatus = '"alertnow":true,"changed"' then
        begin
                regChmelnOn();
        end;

        if KhmelnStatus = 'alertnow":false,"changed"' then
        begin
                regChmelnOff();
        end;

        if KhmelnStatus = 'alertnow":true,"changed":' then
        begin
                regChmelnOn();
        end;

        if KhmelnStatus = 'lertnow":false,"changed":' then
        begin
                regChmelnOff();
        end;

        if KhmelnStatus = 'lertnow":true,"changed":"' then
        begin
                regChmelnOn();
        end;

        if KhmelnStatus = 'ertnow":false,"changed":"' then
        begin
                regChmelnOff();
        end;

        if KhmelnStatus = 'ertnow":true,"changed":"'+fstYear then
        begin
                regChmelnOn();
        end;

        if KhmelnStatus = 'rtnow":false,"changed":"'+fstYear then
        begin
                regChmelnOff();
        end;

        if KhmelnStatus = 'rtnow":true,"changed":"'+fstYear+sndYear then
        begin
                regChmelnOn();
        end;

        if KhmelnStatus = 'tnow":false,"changed":"'+fstYear+sndYear then
        begin
                regChmelnOff();
        end;

        if KhmelnStatus = 'tnow":true,"changed":"'+fstYear+sndYear+trdYear then
        begin
                regChmelnOn();
        end;

        if KhmelnStatus = 'now":false,"changed":"'+fstYear+sndYear+trdYear then
        begin
                regChmelnOff();
        end;

        if KhmelnStatus = 'now":true,"changed":"'+fstYear+sndYear+trdYear+frtYear then
        begin
                regChmelnOn();
        end;

        if KhmelnStatus = 'ow":false,"changed":"'+fstYear+sndYear+trdYear+frtYear then
        begin
                regChmelnOff();
        end;

        if KhmelnStatus = 'ow":true,"changed":"'+fstYear+sndYear+trdYear+frtYear+'-' then
        begin
                regChmelnOn();
        end;

        if KhmelnStatus = 'w":false,"changed":"'+fstYear+sndYear+trdYear+frtYear+'-' then
        begin
                regChmelnOff();
        end;

        if KhmelnStatus = 'w":true,"changed":"'+fstYear+sndYear+trdYear+frtYear+'-'+fstMon then
        begin
                regChmelnOn();
        end;

        if KhmelnStatus = '":false,"changed":"'+fstYear+sndYear+trdYear+frtYear+'-'+fstMon then
        begin
                regChmelnOff();
        end;

        if KhmelnStatus = '":true,"changed":"'+fstYear+sndYear+trdYear+frtYear+'-'+fstMon+sndMon then
        begin
                regChmelnOn();
        end;

        if KhmelnStatus = ':false,"changed":"'+fstYear+sndYear+trdYear+frtYear+'-'+fstMon+sndMon then
        begin
                regChmelnOff();
        end;

        if KhmelnStatus = ':true,"changed":"'+fstYear+sndYear+trdYear+frtYear+'-'+fstMon+sndMon+'-' then
        begin
                regChmelnOn();
        end;

        if KhmelnStatus = 'false,"changed":"'+fstYear+sndYear+trdYear+frtYear+'-'+fstMon+sndMon+'-' then
        begin
                regChmelnOff();
        end;

        if KhmelnStatus = 'true,"changed":"'+fstYear+sndYear+trdYear+frtYear+'-'+fstMon+sndMon+'-'+fstDay then
        begin
                regChmelnOn();
        end;

        CherkStatus := copy(inp, 3072+470, 25);

        if CherkStatus = 'alse,"changed":"'+fstYear+sndYear+trdYear+frtYear+'-'+fstMon+sndMon+'-'+fstDay then
        begin
                regCherkOff();
        end;

        if CherkStatus = 'rue,"changed":"'+fstYear+sndYear+trdYear+frtYear+'-'+fstMon+sndMon+'-'+fstDay+sndDay then
        begin
                regCherkOn();
        end;

        if CherkStatus = 'false,"changed":"'+fstYear+sndYear+trdYear+frtYear+'-'+fstMon+sndMon+'-' then
        begin
                regCherkOff();
        end;

        if CherkStatus = 'true,"changed":"'+fstYear+sndYear+trdYear+frtYear+'-'+fstMon+sndMon+'-'+fstDay then
        begin
                regCherkOn();
        end;

        if CherkStatus = ':false,"changed":"'+fstYear+sndYear+trdYear+frtYear+'-'+fstMon+sndMon then
        begin
                regCherkOff();
        end;

        if CherkStatus = ':true,"changed":"'+fstYear+sndYear+trdYear+frtYear+'-'+fstMon+sndMon+'-'then
        begin
                regCherkOn();
        end;

        if CherkStatus = '":false,"changed":"'+fstYear+sndYear+trdYear+frtYear+'-'+fstMon then
        begin
                regCherkOff();
        end;

        if CherkStatus = '":true,"changed":"'+fstYear+sndYear+trdYear+frtYear+'-'+fstMon+sndMon then
        begin
                regCherkOn();
        end;

        if CherkStatus = 'w":false,"changed":"'+fstYear+sndYear+trdYear+frtYear+'-' then
        begin
                regCherkOff();
        end;

        if CherkStatus = 'w":true,"changed":"'+fstYear+sndYear+trdYear+frtYear+'-'+fstMon then
        begin
                regCherkOn();
        end;

        if CherkStatus = 'ow":false,"changed":"'+fstYear+sndYear+trdYear+frtYear then
        begin
                regCherkOff();
        end;

        if CherkStatus = 'ow":true,"changed":"'+fstYear+sndYear+trdYear+frtYear+'-' then
        begin
                regCherkOn();
        end;

        if CherkStatus = 'now":false,"changed":"'+fstYear+sndYear+trdYear then
        begin
                regCherkOff();
        end;

        if CherkStatus = 'now":true,"changed":"'+fstYear+sndYear+trdYear+frtYear then
        begin
                regCherkOn();
        end;

        if CherkStatus = 'tnow":false,"changed":"'+fstYear+sndYear then
        begin
                regCherkOff();
        end;

        if CherkStatus = 'tnow":true,"changed":"'+fstYear+sndYear+trdYear then
        begin
                regCherkOn();
        end;

        if CherkStatus = 'rtnow":false,"changed":"'+fstYear then
        begin
                regCherkOff();
        end;

        if CherkStatus = 'rtnow":true,"changed":"'+fstYear+sndYear then
        begin
                regCherkOn();
        end;

        if CherkStatus = 'ertnow":false,"changed":"' then
        begin
                regCherkOff();
        end;

        if CherkStatus = 'ertnow":true,"changed":"'+fstYear then
        begin
                regCherkOn();
        end;

        if CherkStatus = 'lertnow":false,"changed":' then
        begin
                regCherkOff();
        end;

        if CherkStatus = 'lertnow":true,"changed":"' then
        begin
                regCherkOn();
        end;

        if CherkStatus = 'alertnow":false,"changed"' then
        begin
                regCherkOff();
        end;

        if CherkStatus = 'alertnow":true,"changed":' then
        begin
                regCherkOn();
        end;

        if CherkStatus = '"alertnow":false,"changed' then
        begin
                regCherkOff();
        end;

        if CherkStatus = '"alertnow":true,"changed"' then
        begin
                regCherkOn();
        end;

        if CherkStatus = '{"alertnow":false,"change' then
        begin
                regCherkOff();
        end;

        if CherkStatus = '{"alertnow":true,"changed' then
        begin
                regCherkOn();
        end;

        if CherkStatus = ':{"alertnow":false,"chang' then
        begin
                regCherkOff();
        end;

        if CherkStatus = ':{"alertnow":true,"change' then
        begin
                regCherkOn();
        end;

        if CherkStatus = '":{"alertnow":false,"chan' then
        begin
                regCherkOff();
        end;

        if CherkStatus = '":{"alertnow":true,"chang' then
        begin
                regCherkOn();
        end;

        if CherkStatus = 'c":{"alertnow":false,"cha' then
        begin
                regCherkOff();
        end;

        if CherkStatus = 'c":{"alertnow":true,"chan' then
        begin
                regCherkOn();
        end;

        if CherkStatus = '4c":{"alertnow":false,"ch' then
        begin
                regCherkOff();
        end;

        if CherkStatus = '4c":{"alertnow":true,"cha' then
        begin
                regCherkOn();
        end;

        if CherkStatus = '44c":{"alertnow":false,"c' then
        begin
                regCherkOff();
        end;

        if CherkStatus = '44c":{"alertnow":true,"ch' then
        begin
                regCherkOn();
        end;

        if CherkStatus = '044c":{"alertnow":false,"' then
        begin
                regCherkOff();
        end;

        if CherkStatus = '044c":{"alertnow":true,"c' then
        begin
                regCherkOn();
        end;

        if CherkStatus = 'u044c":{"alertnow":false,' then
        begin
                regCherkOff();
        end;

        if CherkStatus = 'u044c":{"alertnow":true,"' then
        begin
                regCherkOn();
        end;

        if CherkStatus = '\u044c":{"alertnow":false' then
        begin
                regCherkOff();
        end;

        if CherkStatus = '\u044c":{"alertnow":true,' then
        begin
                regCherkOn();
        end;

        if CherkStatus = '2\u044c":{"alertnow":fals' then
        begin
                regCherkOff();
        end;

        if CherkStatus = '2\u044c":{"alertnow":true' then
        begin
                regCherkOn();
        end;

        ChernivStatus := copy(inp, 3072+632, 25);

        if ChernivStatus = '42\u044c":{"alertnow":fal' then
        begin
                regChernivOff();
        end;

        if ChernivStatus = '42\u044c":{"alertnow":tru' then
        begin
                regChernivOn();
        end;

        if ChernivStatus = '2\u044c":{"alertnow":fals' then
        begin
                regChernivOff();
        end;

        if ChernivStatus = '2\u044c":{"alertnow":true' then
        begin
                regChernivOn();
        end;

        if ChernivStatus = '\u044c":{"alertnow":false' then
        begin
                regChernivOff();
        end;

        if ChernivStatus = '\u044c":{"alertnow":true,' then
        begin
                regChernivOn();
        end;

        if ChernivStatus = 'u044c":{"alertnow":false,' then
        begin
                regChernivOff();
        end;

        if ChernivStatus = 'u044c":{"alertnow":true,"' then
        begin
                regChernivOn();
        end;

        if ChernivStatus = '044c":{"alertnow":false,"' then
        begin
                regChernivOff();
        end;

        if ChernivStatus = '044c":{"alertnow":true,"c' then
        begin
                regChernivOn();
        end;

        if ChernivStatus = '44c":{"alertnow":false,"c' then
        begin
                regChernivOff();
        end;

        if ChernivStatus = '44c":{"alertnow":true,"ch' then
        begin
                regChernivOn();
        end;

        if ChernivStatus = '4c":{"alertnow":false,"ch' then
        begin
                regChernivOff();
        end;

        if ChernivStatus = '4c":{"alertnow":true,"cha' then
        begin
                regChernivOn();
        end;

        if ChernivStatus = 'c":{"alertnow":false,"cha' then
        begin
                regChernivOff();
        end;

        if ChernivStatus = 'c":{"alertnow":true,"chan' then
        begin
                regChernivOn();
        end;

        if ChernivStatus = '":{"alertnow":false,"chan' then
        begin
                regChernivOff();
        end;

        if ChernivStatus = '":{"alertnow":true,"chang' then
        begin
                regChernivOn();
        end;

        if ChernivStatus = ':{"alertnow":false,"chang' then
        begin
                regChernivOff();
        end;

        if ChernivStatus = ':{"alertnow":true,"change' then
        begin
                regChernivOn();
        end;

        if ChernivStatus = '{"alertnow":false,"change' then
        begin
                regChernivOff();
        end;

        if ChernivStatus = '{"alertnow":true,"changed' then
        begin
                regChernivOn();
        end;

        if ChernivStatus = '"alertnow":false,"changed' then
        begin
                regChernivOff();
        end;

        if ChernivStatus = '"alertnow":true,"changed"' then
        begin
                regChernivOn();
        end;

        if ChernivStatus = 'alertnow":false,"changed"' then
        begin
                regChernivOff();
        end;

        if ChernivStatus = 'alertnow":true,"changed":' then
        begin
               regChernivOn();
        end;

        if ChernivStatus = 'lertnow":false,"changed":' then
        begin
                regChernivOff();
        end;

        if ChernivStatus = 'lertnow":true,"changed":"' then
        begin
                regChernivOn();
        end;

        if ChernivStatus = 'ertnow":false,"changed":"' then
        begin
                regChernivOff();
        end;

        if ChernivStatus = 'ertnow":true,"changed":"'+fstYear then
        begin
                regChernivOn();
        end;

        if ChernivStatus = 'rtnow":false,"changed":"'+fstYear then
        begin
                regChernivOff();
        end;

        if ChernivStatus = 'rtnow":true,"changed":"'+fstYear+sndYear then
        begin
                regChernivOn();
        end;

        if ChernivStatus = 'tnow":false,"changed":"'+fstYear+sndYear then
        begin
                regChernivOff();
        end;

        if ChernivStatus = 'tnow":true,"changed":"'+fstYear+sndYear+trdYear then
        begin
                regChernivOn();
        end;

        if ChernivStatus = 'now":false,"changed":"'+fstYear+sndYear+trdYear then
        begin
                regChernivOff();
        end;

        if ChernivStatus = 'now":true,"changed":"'+fstYear+sndYear+trdYear+frtYear then
        begin
                regChernivOn();
        end;

        if ChernivStatus = 'ow":false,"changed":"'+fstYear+sndYear+trdYear+frtYear+'-' then
        begin
                regChernivOff();
        end;

        if ChernivStatus = 'ow":true,"changed":"'+fstYear+sndYear+trdYear+frtYear+'-'+fstMon then
        begin
                regChernivOn();
        end;

        if ChernivStatus = 'w":false,"changed":"'+fstYear+sndYear+trdYear+frtYear+'-'+fstMon then
        begin
                regChernivOff();
        end;

        if ChernivStatus = 'w":true,"changed":"'+fstYear+sndYear+trdYear then
        begin
                regChernivOn();
        end;

        if ChernivStatus = '":false,"changed":"'+fstYear+sndYear+trdYear+frtYear then
        begin
                regChernivOff();
        end;

        if ChernivStatus = '":true,"changed":"'+fstYear+sndYear+trdYear+frtYear+'-' then
        begin
                regChernivOn();
        end;

        if ChernivStatus = ':false,"changed":"'+fstYear+sndYear+trdYear+frtYear+'-'+fstMon then
        begin
                regChernivOff();
        end;

        if ChernivStatus = ':true,"changed":"'+fstYear+sndYear+trdYear+frtYear+'-'+fstMon+sndMon then
        begin
                regChernivOn();
        end;

        if ChernivStatus = 'false,"changed":"'+fstYear+sndYear+trdYear+frtYear+'-'+fstMon+sndMon+'-' then
        begin
                regChernivOff();
        end;

        if ChernivStatus = 'true,"changed":"'+fstYear+sndYear+trdYear+frtYear+'-'+fstMon+sndMon+'-'+fstDay then
        begin
                regChernivOn();
        end;

        ChernihStatus := copy(inp, 3072+800, 25);

        if ChernihStatus = '442\u044c":{"alertnow":fa' then
        begin
                regChernihOff();
        end;

        if ChernihStatus = '442\u044c":{"alertnow":tr' then
        begin
                regChernihOn();
        end;

        if ChernihStatus = '42\u044c":{"alertnow":fal' then
        begin
                regChernihOff();
        end;

        if ChernihStatus = '42\u044c":{"alertnow":tru' then
        begin
                regChernihOn();
        end;

        if ChernihStatus = '2\u044c":{"alertnow":fals' then
        begin
                regChernihOff();
        end;

        if ChernihStatus = '2\u044c":{"alertnow":true' then
        begin
                regChernihOn();
        end;

        if ChernihStatus = '\u044c":{"alertnow":false' then
        begin
                regChernihOff();
        end;

        if ChernihStatus = '\u044c":{"alertnow":true,' then
        begin
                regChernihOn();
        end;

        if ChernihStatus = 'u044c":{"alertnow":false,' then
        begin
                regChernihOff();
        end;

        if ChernihStatus = 'u044c":{"alertnow":true,"' then
        begin
                regChernihOn();
        end;

        if ChernihStatus = '044c":{"alertnow":false,"' then
        begin
                regChernihOff();
        end;

        if ChernihStatus = '044c":{"alertnow":true,"c' then
        begin
                regChernihOn();
        end;

        if ChernihStatus = '44c":{"alertnow":false,"c' then
        begin
                regChernihOff();
        end;

        if ChernihStatus = '44c":{"alertnow":true,"ch' then
        begin
                regChernihOn();
        end;

        if ChernihStatus = '4c":{"alertnow":false,"ch' then
        begin
                regChernihOff();
        end;

        if ChernihStatus = '4c":{"alertnow":true,"cha' then
        begin
                regChernihOn();
        end;

        if ChernihStatus = 'c":{"alertnow":false,"cha' then
        begin
                regChernihOff();
        end;

        if ChernihStatus = 'c":{"alertnow":true,"chan' then
        begin
                regChernihOn();
        end;

        if ChernihStatus = '":{"alertnow":false,"chan' then
        begin
                regChernihOff();
        end;

        if ChernihStatus = '":{"alertnow":true,"chang' then
        begin
                regChernihOn();
        end;

        if ChernihStatus = ':{"alertnow":false,"chang' then
        begin
                regChernihOff();
        end;

        if ChernihStatus = ':{"alertnow":true,"change' then
        begin
                regChernihOn();
        end;

        if ChernihStatus = '{"alertnow":false,"change' then
        begin
                regChernihOff();
        end;

        if ChernihStatus = '{"alertnow":true,"changed' then
        begin
                regChernihOn();
        end;

        if ChernihStatus = '"alertnow":false,"changed' then
        begin
                regChernihOff();
        end;

        if ChernihStatus = '"alertnow":true,"changed"' then
        begin
                regChernihOn();
        end;

        if ChernihStatus = 'alertnow":false,"changed"' then
        begin
                regChernihOff();
        end;

        if ChernihStatus = 'alertnow":true,"changed":' then
        begin
                regChernihOn();
        end;

        if ChernihStatus = 'lertnow":false,"changed":' then
        begin
                regChernihOff();
        end;

        if ChernihStatus = 'lertnow":true,"changed":"' then
        begin
                regChernihOn();
        end;

        if ChernihStatus = 'ertnow":false,"changed":"' then
        begin
                regChernihOff();
        end;

        if ChernihStatus = 'ertnow":true,"changed":"'+fstYear then
        begin
                regChernihOn();
        end;

        if ChernihStatus = 'rtnow":false,"changed":"'+fstYear then
        begin
                regChernihOff();
        end;

        if ChernihStatus = 'rtnow":true,"changed":"'+fstYear+sndYear then
        begin
                regChernihOn();
        end;

        if ChernihStatus = 'tnow":false,"changed":"'+fstYear+sndYear then
        begin
                regChernihOff();
        end;

        if ChernihStatus = 'tnow":true,"changed":"'+fstYear+sndYear+trdYear then
        begin
                regChernihOn();
        end;

        if ChernihStatus = 'now":false,"changed":"'+fstYear+sndYear+trdYear then
        begin
                regChernihOff();
        end;

        if ChernihStatus = 'now":true,"changed":"'+fstYear+sndYear+trdYear+frtYear then
        begin
                regChernihOn();
        end;

        if ChernihStatus = 'ow":false,"changed":"'+fstYear+sndYear+trdYear+frtYear then
        begin
                regChernihOff();
        end;

        if ChernihStatus = 'ow":true,"changed":"'+fstYear+sndYear+trdYear+frtYear+'-' then
        begin
                regChernihOn();
        end;

        if ChernihStatus = 'w":false,"changed":"'+fstYear+sndYear+trdYear+frtYear+'-' then
        begin
                regChernihOff();
        end;

        if ChernihStatus = 'w":true,"changed":"'+fstYear+sndYear+trdYear+frtYear+'-'+fstMon then
        begin
                regChernihOn();
        end;

        if ChernihStatus = '":false,"changed":"'+fstYear+sndYear+trdYear+frtYear+'-'+fstMon then
        begin
                regChernihOff();
        end;

        if ChernihStatus = '":true,"changed":"'+fstYear+sndYear+trdYear+frtYear+'-'+fstMon+sndMon then
        begin
                regChernihOn();
        end;

        if ChernihStatus = ':false,"changed":"'+fstYear+sndYear+trdYear+frtYear+'-'+fstMon+sndMon then
        begin
                regChernihOff();
        end;

        if ChernihStatus = ':true,"changed":"'+fstYear+sndYear+trdYear+frtYear+'-'+fstMon+sndMon+'-' then
        begin
                regChernihOn();
        end;

        if ChernihStatus = 'false,"changed":"'+fstYear+sndYear+trdYear+frtYear+'-'+fstMon+sndMon+'-' then
        begin
                regChernihOff();
        end;

        if ChernihStatus = 'true,"changed":"'+fstYear+sndYear+trdYear+frtYear+'-'+fstMon+sndMon+'-'+fstDay then
        begin
                regChernihOn();
        end;

        KyivCityStatus := copy(inp, 3072+885, 25);

        if KyivCityStatus = '0457\u0432":{"alertnow":f' then
        begin
                regKyivCityOff();
        end;

        if KyivCityStatus = '0457\u0432":{"alertnow":t' then
        begin
                regKyivCityOn();
        end;

        if KyivCityStatus = '457\u0432":{"alertnow":fa' then
        begin
                regKyivCityOff();
        end;

        if KyivCityStatus = '457\u0432":{"alertnow":tr' then
        begin
                regKyivCityOn();
        end;

        if KyivCityStatus = '57\u0432":{"alertnow":fal' then
        begin
                regKyivCityOff();
        end;

        if KyivCityStatus = '57\u0432":{"alertnow":tru' then
        begin
                regKyivCityOn();
        end;

        if KyivCityStatus = '7\u0432":{"alertnow":fals' then
        begin
                regKyivCityOff();
        end;

        if KyivCityStatus = '7\u0432":{"alertnow":true' then
        begin
                regKyivCityOn();
        end;

        if KyivCityStatus = '\u0432":{"alertnow":false' then
        begin
                regKyivCityOff();
        end;

        if KyivCityStatus = '\u0432":{"alertnow":true,' then
        begin
                regKyivCityOn();
        end;

        if KyivCityStatus = 'u0432":{"alertnow":false,' then
        begin
                regKyivCityOff();
        end;

        if KyivCityStatus = 'u0432":{"alertnow":true,"' then
        begin
                regKyivCityOn();
        end;

        if KyivCityStatus = '0432":{"alertnow":false,"' then
        begin
                regKyivCityOff();
        end;

        if KyivCityStatus = '0432":{"alertnow":true,"c' then
        begin
                regKyivCityOn();
        end;

        if KyivCityStatus = '432":{"alertnow":false,"c' then
        begin
                regKyivCityOff();
        end;

        if KyivCityStatus = '432":{"alertnow":true,"ch' then
        begin
                regKyivCityOn();
        end;

        if KyivCityStatus = '32":{"alertnow":false,"ch' then
        begin
                regKyivCityOff();
        end;

        if KyivCityStatus = '32":{"alertnow":true,"cha' then
        begin
                regKyivCityOn();
        end;

        if KyivCityStatus = '2":{"alertnow":false,"cha' then
        begin
                regKyivCityOff();
        end;

        if KyivCityStatus = '2":{"alertnow":true,"chan' then
        begin
                regKyivCityOn();
        end;

        if KyivCityStatus = '":{"alertnow":false,"chan' then
        begin
                regKyivCityOff();
        end;

        if KyivCityStatus = '":{"alertnow":true,"chang' then
        begin
                regKyivCityOn();
        end;

        if KyivCityStatus = ':{"alertnow":false,"chang' then
        begin
                regKyivCityOff();
        end;

        if KyivCityStatus = ':{"alertnow":true,"change' then
        begin
                regKyivCityOn();
        end;

        if KyivCityStatus = '{"alertnow":false,"change' then
        begin
                regKyivCityOff();
        end;

        if KyivCityStatus = '{"alertnow":true,"changed' then
        begin
                regKyivCityOn();
        end;

        if KyivCityStatus = '"alertnow":false,"changed' then
        begin
                regKyivCityOff();
        end;

        if KyivCityStatus = '"alertnow":true,"changed"' then
        begin
                regKyivCityOn();
        end;

        if KyivCityStatus = 'alertnow":false,"changed"' then
        begin
                regKyivCityOff();
        end;

        if KyivCityStatus = 'alertnow":true,"changed":' then
        begin
                regKyivCityOn();
        end;

        if KyivCityStatus = 'lertnow":false,"changed":' then
        begin
                regKyivCityOff();
        end;

        if KyivCityStatus = 'lertnow":true,"changed":"' then
        begin
                regKyivCityOn();
        end;

        if KyivCityStatus = 'ertnow":false,"changed":"' then
        begin
                regKyivCityOff();
        end;

        if KyivCityStatus = 'ertnow":true,"changed":"'+fstYear then
        begin
                regKyivCityOn();
        end;

        if KyivCityStatus = 'rtnow":false,"changed":"'+fstYear then
        begin
                regKyivCityOff();
        end;

        if KyivCityStatus = 'rtnow":true,"changed":"'+fstYear+sndYear then
        begin
                regKyivCityOn();
        end;

        if KyivCityStatus = 'tnow":false,"changed":"'+fstYear+sndYear then
        begin
                regKyivCityOff();
        end;

        if KyivCityStatus = 'tnow":true,"changed":"'+fstYear+sndYear+trdYear then
        begin
                regKyivCityOn();
        end;

        if KyivCityStatus = 'now":false,"changed":"'+fstYear+sndYear+trdYear then
        begin
                regKyivCityOff();
        end;

        if KyivCityStatus = 'now":true,"changed":"'+fstYear+sndYear+trdYear+frtYear then
        begin
                regKyivCityOn();
        end;

        if KyivCityStatus = 'ow":false,"changed":"'+fstYear+sndYear+trdYear+frtYear then
        begin
                regKyivCityOff();
        end;

        if KyivCityStatus = 'ow":true,"changed":"'+fstYear+sndYear+trdYear+frtYear+'-' then
        begin
                regKyivCityOn();
        end;

        if KyivCityStatus = 'w":false,"changed":"'+fstYear+sndYear+trdYear+frtYear+'-' then
        begin
                regKyivCityOff();
        end;

        if KyivCityStatus = 'w":true,"changed":"'+fstYear+sndYear+trdYear+frtYear+'-'+fstMon then
        begin
                regKyivCityOn();
        end;

        if KyivCityStatus = '":false,"changed":"'+fstYear+sndYear+trdYear+frtYear+'-'+fstMon then
        begin
                regKyivCityOff();
        end;

        if KyivCityStatus = '":true,"changed":"'+fstYear+sndYear+trdYear+frtYear+'-'+fstMon+sndMon then
        begin
                regKyivCityOn();
        end;

        if KyivCityStatus = ':false,"changed":"'+fstYear+sndYear+trdYear+frtYear+'-'+fstMon+sndMon then
        begin
                regKyivCityOff();
        end;

        if KyivCityStatus = ':true,"changed":"'+fstYear+sndYear+trdYear+frtYear+'-'+fstMon+sndMon+'-' then
        begin
                regKyivCityOn();
        end;

        if KyivCityStatus = 'false,"changed":"'+fstYear+sndYear+trdYear+frtYear+'-'+fstMon+sndMon+'-' then
        begin
                regKyivCityOff();
        end;

        if KyivCityStatus = 'true,"changed":"'+fstYear+sndYear+trdYear+frtYear+'-'+fstMon+sndMon+'-'+fstDay then
        begin
                regKyivCityOn();
        end;

        ZapStatus := copy(inp, 1024+147, 11);

        if ZapStatus = 'ow":false,"' then
        begin
                regZapOff();
        end;

        if ZapStatus = 'tnow":false' then
        begin
                regZapOff();
        end;

        if ZapStatus = 'tnow":true,' then
        begin
                regZapOn();
        end;

        if ZapStatus = 'now":false,' then
        begin
                regZapOff();
        end;

        if ZapStatus = 'now":true,"' then
        begin
                regZapOn();
        end;

        if ZapStatus = 'w":false,"c' then
        begin
                regZapOff();
        end;

        if ZapStatus = 'w":true,"ch' then
        begin
                regZapOn();
        end;

        if ZapStatus = '":false,"ch' then
        begin
                regZapOff();
        end;

        if ZapStatus = '":true,"cha' then
        begin
                regZapOn();
        end;

        if ZapStatus = ':false,"cha' then
        begin
                regZapOff();
        end;

        if ZapStatus = ':true,"chan' then
        begin
                regZapOn();
        end;

        if ZapStatus = 'false,"chan' then
        begin
                regZapOff();
        end;

        if ZapStatus = 'true,"chang' then
        begin
                regZapOn();
        end;

        if ZapStatus = 'ow":true,"c' then
        begin
                regZapOn();
        end;
        //edit1.text := KheStatus;
        //edit1.text := KhmelnStatus;
        //edit1.text := KyivCityStatus;
        //edit1.text := ChernihStatus;
        //edit1.text := SumStatus;
        VinStatus := '';
        VolStatus := '';
        DnStatus := '';
        DonStatus := '';
        ZhytStatus := '';
        ZakStatus := '';
        ZapStatus := '';
        IvanoStatus := '';
        KyivStatus := '';
        KiroStatus := '';
        LuhStatus := '';
        LvivStatus := '';
        MykStatus := '';
        OdesStatus := '';
        PoltStatus := '';
        RivStatus := '';
        SumStatus := '';
        TernStatus := '';
        KhaStatus := '';
        KheStatus := '';
        KhmelnStatus := '';
        CherkStatus := '';
        ChernivStatus := '';
        ChernihStatus := '';
        KyivCityStatus := '';
        end;
end;

procedure TForm1.callapiClick(Sender: TObject);
begin
        sec := 15;
        cdNatur := true;
        Timer1.Enabled := true;
        Timer1.Interval := 1000;
        Timer2.Enabled := true;
        Timer2.Interval := 500; //1000
        Request(Form1);
end;

procedure TForm1.Connect2Click(Sender: TObject);
begin
      statusC := true;
end;

procedure TForm1.Disconnect1Click(Sender: TObject);
begin
      if debugMode = false then
      begin
      debugMode := true;
      throbber.Visible := true;
      onlineStatus.Visible := false;
      Status.caption := 'Offline';

      noWeb.visible := true;
      netStatus.Caption := 'Disconnected!';
      netStatus.Visible := true;

      MessageBox(0,'Disconnected. Click "Update [Q]" to reconnect.', 'Air Alert', MB_ICONWARNING);
      end else if debugMode = true then
      begin
      // nothing
      end;
end;

procedure TForm1.Crash1Click(Sender: TObject);
begin
        MessageBox(0,'No Internet Connection!', 'Air Alert', MB_ICONWARNING);
end;

procedure TForm1.Button4Click(Sender: TObject);
begin
    GetLocalTime(SystemTime);
    clockTimer.Caption := Format('%2.2d:%2.2d:%2.2d',[SystemTime.wHour, SystemTime.wMinute, SystemTime.wSecond]);
    Hour := Format('%2.2d',[SystemTime.wHour]);
    dateText.caption := DateToStr(Date);
    daySince.Caption := inttostr(DaysBetween(EncodeDate(2022,2,23), Date));
        if SystemTime.wHour = 21 then
        begin
        pm9.BringToFront;
        end else if SystemTime.wHour = 22 then
        begin
        pm10.BringToFront;
        end else if SystemTime.wHour = 23 then
        begin
        pm11.BringToFront;
        end else if SystemTime.wHour = 00 then
        begin
        am12.BringToFront;
        end else if SystemTime.wHour = 01 then
        begin
        am1.BringToFront;
        end else if SystemTime.wHour = 02 then
        begin
        am2.BringToFront;
        end else if SystemTime.wHour = 03 then
        begin
        am3.BringToFront;
        end else if SystemTime.wHour = 04 then
        begin
        am4.BringToFront;
        end else if SystemTime.wHour = 05 then
        begin
        am5.BringToFront;
        end else if SystemTime.wHour = 06 then
        begin
        am6.BringToFront;
        end else if SystemTime.wHour = 07 then
        begin
        am7.BringToFront;
        end else if SystemTime.wHour = 08 then
        begin
        am8.BringToFront;
        end else if SystemTime.wHour = 09 then
        begin
        am9.BringToFront;
        end else if SystemTime.wHour = 10 then
        begin
        am10.BringToFront;
        end else if SystemTime.wHour = 11 then
        begin
        am11.BringToFront;
        end else if SystemTime.wHour = 12 then
        begin
        pm12.BringToFront;
        end else if SystemTime.wHour = 13 then
        begin
        pm1.BringToFront;
        end else if SystemTime.wHour = 14 then
        begin
        pm2.BringToFront;
        end else if SystemTime.wHour = 15 then
        begin
        pm3.BringToFront;
        end else if SystemTime.wHour = 16 then
        begin
        pm4.BringToFront;
        end else if SystemTime.wHour = 17 then
        begin
        pm5.BringToFront;
        end else if SystemTime.wHour = 18 then
        begin
        pm6.BringToFront;
        end else if SystemTime.wHour = 19 then
        begin
        pm7.BringToFront;
        end else if SystemTime.wHour = 20 then
        begin
        pm8.BringToFront;
        end;
end;

procedure TForm1.Button3Click(Sender: TObject);
begin
        Application.helpfile := 'help.hlp'; // doesn't work, needs a fix
end;

procedure TForm1.Button5Click(Sender: TObject);
begin
        if Disconnect1.Checked = true then
        begin
        Disconnect1.Checked := false;
        throbber.Visible := false;
        onlineStatus.Visible := true;
        Status.caption := 'Online';

        noWeb.visible := false;
        netStatus.Caption := 'No Connection!';
        netStatus.Visible := false;

        debugMode := false;
        updateBtnClick(Form1);
        end else if Disconnect1.Checked = false then
        begin
        debugMode := false;
        updateBtnClick(Form1);
        end;


end;

procedure TForm1.Update1Click(Sender: TObject);
begin
        if Disconnect1.Checked = true then
        begin
        Disconnect1.Checked := false;
        throbber.Visible := false;
        onlineStatus.Visible := true;
        Status.caption := 'Online';

        noWeb.visible := false;
        netStatus.Caption := 'No Connection!';
        netStatus.Visible := false;

        debugMode := false;
        updateBtnClick(Form1);
        end else if Disconnect1.Checked = false then
        begin
        debugMode := false;
        updateBtnClick(Form1);
        end;


end;

procedure TForm1.Button6Click(Sender: TObject);
begin
     if debugMode = false then
      begin
      debugMode := true;
      throbber.Visible := true;
      onlineStatus.Visible := false;
      Status.caption := 'Offline';

      noWeb.visible := true;
      netStatus.Caption := 'Disconnected!';
      netStatus.Visible := true;

      MessageBox(0,'Disconnected. Click "Update [Q]" to reconnect.', 'Air Alert', MB_ICONWARNING);
      end else if debugMode = true then
      begin
      // nothing
      end;
end;

procedure TForm1.Help2Click(Sender: TObject);
var
ErrorCode : integer;
begin
        ErrorCode := Integer(ShellExecute(Handle, 'open', 'help.hlp', nil, nil, SW_SHOWNORMAL));
        if ErrorCode = 2 then
        begin
        MessageBox(0,'Help file is not installed or missing.'+ #13#10 + #13#10 +'The manual is not available in portable version.'+ #13#10 +'Run a setup file from the disk image to install or fix a full version.', 'Air Alert', MB_ICONWARNING);
        end;
end;

end.


