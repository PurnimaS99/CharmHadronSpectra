 const int n=1000;

    int ntrack=0,PID[n]={0},charge[n]={0}, V0MMult=0;
    double px[n]={0},py[n]={0},pz[n]={0},pT=0,mass[n]={0};
    double eta[n]={0},rap[n]={0},phi[n]={0}, energy[n]={0};

void rapspectra()
{
    gStyle->SetPalette(kRainBow);
    TFile *f = TFile::Open("/home/puri/pythia8308/examples/practice/finalpp/finalpp.root");

    TCanvas *c = new TCanvas("c","c", 750,600);
    auto rapsp = new TH2F("rapsp","This is the rapidity distribution",10,-2.0,2.0,10,1e-06,10.0);
    rapsp->GetYaxis()->SetTitle("count");
    // pTsp->GetYaxis()->SetTitleOffset(1.3); pTsp->GetYaxis()->CenterTitle(true);
    rapsp->GetXaxis()->SetTitle("eta");// The text within the inverted commas will be written in the latex format
    // pTsp->GetXaxis()->CenterTitle(true);
    c->SetLogy();
    c->Draw();

    TTree *theTree = (TTree*)f->Get("t");
	  
	theTree->SetBranchAddress("ntrack", &ntrack);  //ntrack is the size of the tree (fill only final chargedparticles)  
    theTree->SetBranchAddress("V0MMult", &V0MMult);
	theTree->SetBranchAddress("PID", PID);
	theTree->SetBranchAddress("charge",charge);
	theTree->SetBranchAddress("px",px);
	theTree->SetBranchAddress("py",py);
	theTree->SetBranchAddress("pz",pz);
    theTree->SetBranchAddress("energy",energy);
	

    const Int_t XBINS =12; 
    Double_t etabins[13] = {-3.0, -2.5, -2.0, -1.5, -1.0, -0.5, 0, 0.5, 1.0, 1.5, 2.0, 2.5, 3.0};

    TH1D *hDs= new TH1D("", "", XBINS,etabins);
    hDs->SetLineColor(kRed +2);
    hDs->SetMarkerSize(2);
   
     TH1D *hDp= new TH1D("", "", XBINS,etabins);
    hDp->SetLineColor(kGreen +2);
    hDp->  SetMarkerSize(2);
   
     TH1D *hDZero= new TH1D("", "", XBINS,etabins);
    hDZero->SetLineColor(kBlue);
    hDZero->SetMarkerSize(2);
    
     TH1D *hlambc= new TH1D("", "", XBINS,etabins);
    hlambc->SetLineColor(kPink);
    hlambc->SetMarkerSize(2);
   
     TH1D *hJsi= new TH1D("", "", XBINS,etabins);
    hJsi->SetLineColor(kYellow +2);
    hJsi->SetMarkerSize(2);

   

    TLorentzVector *vec = new TLorentzVector();

    const Int_t nevents = (Int_t)theTree->GetEntries();
    // int nevents = 10000000;

    int counter(0);
    for (int i = 0; i < nevents; i++)
    {
        theTree->GetEntry(i);
        // if(V0MMult<50) continue;
        counter++;

        for (int j = 0; j < ntrack; j++)
        { 
          vec->SetPxPyPzE(px[j], py[j], pz[j], energy[j]);
            if(abs(vec->Eta())<3.0 && vec->Pt()>0.15 && abs(PID[j])==431) hDs->Fill(vec->Eta());
            if(abs(vec->Eta())<3.0 && vec->Pt()>0.15 && abs(PID[j])==411) hDp->Fill(vec->Eta());
            if(abs(vec->Eta())<3.0 && vec->Pt()>0.15 && abs(PID[j])==421) hDZero->Fill(vec->Eta());
            if(abs(vec->Eta())<3.0 && vec->Pt()>0.15 && abs(PID[j])==4122) hlambc->Fill(vec->Eta());
            if(abs(vec->Eta())<3.0 && vec->Pt()>0.15 && PID[j]==443) hJsi->Fill(vec->Eta());


            vec->Clear();

           
          
                       
        } // track loop ends
    }

hDs->SetMarkerStyle(20);
hDs->SetMarkerSize(1.5);
hDp->SetMarkerStyle(22);
hDp->SetMarkerSize(1.5);
hDZero->SetMarkerStyle(24);
hDZero->SetMarkerSize(1.5);
hlambc->SetMarkerStyle(26);
hlambc->SetMarkerSize(1.5);

hJsi->SetMarkerStyle(28);
hJsi->SetMarkerSize(1.5);

cout<<"Total Event: "<<nevents<<" Selected Events: "<<counter<<endl;

for(int bin=1; bin<=XBINS; bin++){
    hDs->SetBinContent(bin, hDs->GetBinContent(bin)/hDs->GetBinWidth(bin));
    hDp->SetBinContent(bin, hDp->GetBinContent(bin)/hDp->GetBinWidth(bin));
    hDZero->SetBinContent(bin, hDZero->GetBinContent(bin)/hDZero->GetBinWidth(bin));
    hlambc->SetBinContent(bin, hlambc->GetBinContent(bin)/hlambc->GetBinWidth(bin));
    hJsi->SetBinContent(bin, hJsi->GetBinContent(bin)/hJsi->GetBinWidth(bin));

    cout << "The content in" << bin << "= " << hJsi->GetBinContent(bin) << endl;
}

hDs->Scale(1.0/(counter));
hDp->Scale(1.0/(counter));
hDZero->Scale(1.0/(counter));
hlambc->Scale(1.0/(counter));
hJsi->Scale(1.0/(counter));

for(int bin=1; bin<=XBINS; bin++)
{
    
    cout << "The content in" << bin << "= " << hJsi->GetBinContent(bin) << endl;
}


    rapsp->Draw();
     hDs->Draw("pesame");
     hDp->Draw("pesame");
     hDZero->Draw("pesame");
      hlambc->Draw("pesame");
     hJsi->Draw("pesame");

  TFile *f1 = new TFile("etaspectra_plot.root", "recreate"); //------- Name Change
  hDs->Write("Ds"); 
  hDp->Write("Dp");
  hDZero->Write("DZero");
  hlambc->Write("lambc");
  hJsi->Write("Jsi");
f1->Close();

    
}