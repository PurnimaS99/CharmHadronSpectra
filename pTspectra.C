    const int n=1000;

    int ntrack=0,PID[n]={0},charge[n]={0}, V0MMult=0;
    double px[n]={0},py[n]={0},pz[n]={0},pT=0,mass[n]={0};
    double eta[n]={0},rap[n]={0},phi[n]={0}, energy[n]={0};

void pTspectra()
{
    gStyle->SetPalette(kRainBow);
    TFile *f = TFile::Open("/home/puri/pythia8308/examples/practice/finalpp/merged_pp.root");

    TCanvas *c = new TCanvas("c","c", 750,600);
    auto pTsp = new TH2F("pTsp","This is the pT distribution",10,0.0,10.0,10,0.001,1e07);
    pTsp->GetYaxis()->SetTitle("count");
    // pTsp->GetYaxis()->SetTitleOffset(1.3); pTsp->GetYaxis()->CenterTitle(true);
    pTsp->GetXaxis()->SetTitle("p_{T} (GeV/c)");
    // pTsp->GetXaxis()->CenterTitle(true);
    c->SetLogy();
    c->Draw();

    //   TCanvas *c1 = new TCanvas("c1","c1", 750,600);
    // auto pTsp1 = new TH2F("pTsp","This is the pT distribution",10,0.0,10.0,10,0.001,1e07);
    // pTsp1->GetYaxis()->SetTitle("count");
    // // pTsp->GetYaxis()->SetTitleOffset(1.3); pTsp->GetYaxis()->CenterTitle(true);
    // pTsp1->GetXaxis()->SetTitle("p_{T} (GeV/c)");
    // // pTsp->GetXaxis()->CenterTitle(true);
    // c1->SetLogy();
    // c1->Draw();

    //   TCanvas *c2 = new TCanvas("c2","c2", 750,600);
    // auto pTsp2 = new TH2F("pTsp","This is the pT distribution",10,0.0,10.0,10,0.001,1e07);
    // pTsp2->GetYaxis()->SetTitle("count");
    // // pTsp->GetYaxis()->SetTitleOffset(1.3); pTsp->GetYaxis()->CenterTitle(true);
    // pTsp2->GetXaxis()->SetTitle("p_{T} (GeV/c)");
    // // pTsp->GetXaxis()->CenterTitle(true);
    // c2->SetLogy();
    // c2->Draw();

    //   TCanvas *c3 = new TCanvas("c3","c3", 750,600);
    // auto pTsp3 = new TH2F("pTsp","This is the pT distribution",10,0.0,10.0,10,0.001,1e07);
    // pTsp3->GetYaxis()->SetTitle("count");
    // // pTsp->GetYaxis()->SetTitleOffset(1.3); pTsp->GetYaxis()->CenterTitle(true);
    // pTsp3->GetXaxis()->SetTitle("p_{T} (GeV/c)");
    // // pTsp->GetXaxis()->CenterTitle(true);
    // c3->SetLogy();
    // c3->Draw();

    //   TCanvas *c4 = new TCanvas("c4","c4", 750,600);
    // auto pTsp4 = new TH2F("pTsp","This is the pT distribution",10,0.0,10.0,10,0.001,1e07);
    // pTsp4->GetYaxis()->SetTitle("count");
    // // pTsp->GetYaxis()->SetTitleOffset(1.3); pTsp->GetYaxis()->CenterTitle(true);
    // pTsp4->GetXaxis()->SetTitle("p_{T} (GeV/c)");
    // // pTsp->GetXaxis()->CenterTitle(true);
    // c4->SetLogy();
    // c4->Draw();

    TTree *theTree = (TTree*)f->Get("t");
	  
	theTree->SetBranchAddress("ntrack", &ntrack);  //ntrack is the size of the tree (fill only final chargedparticles)  
    theTree->SetBranchAddress("V0MMult", &V0MMult);
	theTree->SetBranchAddress("PID", PID);
	theTree->SetBranchAddress("charge",charge);
	theTree->SetBranchAddress("px",px);
	theTree->SetBranchAddress("py",py);
	theTree->SetBranchAddress("pz",pz);
    theTree->SetBranchAddress("energy",energy);
	

    const Int_t XBINS = 15; 
    Double_t pTbins[16] = {0.0,0.3,0.5,0.75,1.0,1.25,1.5,1.75,2.0,2.5,3.0,3.5,4.0,5.0,7.0,10.0};

    TH1D *hDs0= new TH1D("", "", XBINS,pTbins);
    hDs0->SetLineColor(kRed +2);
    hDs0->SetMarkerSize(2);
   
     TH1D *hDs1= new TH1D("", "", XBINS,pTbins);
    hDs1->SetLineColor(kGreen +2);
    hDs1->  SetMarkerSize(2);
   
     TH1D *hDs2= new TH1D("", "", XBINS,pTbins);
    hDs2->SetLineColor(kBlue);
    hDs2->SetMarkerSize(2);
    
     
    TH1D *hDp0= new TH1D("", "", XBINS,pTbins);
    hDp0->SetLineColor(kRed +2);
    hDp0->SetMarkerSize(2);
   
     TH1D *hDp1= new TH1D("", "", XBINS,pTbins);
    hDp1->SetLineColor(kGreen +2);
    hDp1->  SetMarkerSize(2);
   
     TH1D *hDp2= new TH1D("", "", XBINS,pTbins);
    hDp2->SetLineColor(kBlue);
    hDp2->SetMarkerSize(2);
    
     
    TH1D *hDZero0= new TH1D("", "", XBINS,pTbins);
    hDZero0->SetLineColor(kRed +2);
    hDZero0->SetMarkerSize(2);
   
     TH1D *hDZero1= new TH1D("", "", XBINS,pTbins);
    hDZero1->SetLineColor(kGreen +2);
    hDZero1->  SetMarkerSize(2);
   
     TH1D *hDZero2= new TH1D("", "", XBINS,pTbins);
    hDZero2->SetLineColor(kBlue);
    hDZero2->SetMarkerSize(2);
    
     
    TH1D *hlambc0= new TH1D("", "", XBINS,pTbins);
    hlambc0->SetLineColor(kRed +2);
    hlambc0->SetMarkerSize(2);
   
     TH1D *hlambc1= new TH1D("", "", XBINS,pTbins);
    hlambc1->SetLineColor(kGreen +2);
    hlambc1->  SetMarkerSize(2);
   
     TH1D *hlambc2= new TH1D("", "", XBINS,pTbins);
    hlambc2->SetLineColor(kBlue);
    hlambc2->SetMarkerSize(2);
    
     
    TH1D *hJsi0= new TH1D("", "", XBINS,pTbins);
    hJsi0->SetLineColor(kRed +2);
    hJsi0->SetMarkerSize(2);
   
     TH1D *hJsi1= new TH1D("", "", XBINS,pTbins);
    hJsi1->SetLineColor(kGreen +2);
    hJsi1->  SetMarkerSize(2);
   
     TH1D *hJsi2= new TH1D("", "", XBINS,pTbins);
    hJsi2->SetLineColor(kBlue);
    hJsi2->SetMarkerSize(2);

   

    TLorentzVector *vec = new TLorentzVector();

    // const Int_t nevents = (Int_t)theTree->GetEntries();
    int nevents = 1000000;

    int counter(0);
    for (int i = 0; i < nevents; i++)
    {
        theTree->GetEntry(i);
        // if(V0MMult<50) continue;
        counter++;

        for (int j = 0; j < ntrack; j++)
        { 
          vec->SetPxPyPzE(px[j], py[j], pz[j], energy[j]);
            if(abs(vec->Eta())<2.0 && vec->Pt()>0.15 && abs(PID[j])==431 && V0MMult<16 && V0MMult>=12) hDs0->Fill(vec->Pt());
            if(abs(vec->Eta())<2.0 && vec->Pt()>0.15 && abs(PID[j])==431 && V0MMult<12 && V0MMult>=9) hDs1->Fill(vec->Pt());
            if(abs(vec->Eta())<2.0 && vec->Pt()>0.15 && abs(PID[j])==431 && V0MMult<9 && V0MMult>=6) hDs2->Fill(vec->Pt());

            if(abs(vec->Eta())<2.0 && vec->Pt()>0.15 && abs(PID[j])==411 && V0MMult<16 && V0MMult>=12) hDp0->Fill(vec->Pt());
            if(abs(vec->Eta())<2.0 && vec->Pt()>0.15 && abs(PID[j])==411 && V0MMult<12 && V0MMult>=9) hDp1->Fill(vec->Pt());
            if(abs(vec->Eta())<2.0 && vec->Pt()>0.15 && abs(PID[j])==411 && V0MMult<9 && V0MMult>=6) hDp2->Fill(vec->Pt());

            if(abs(vec->Eta())<2.0 && vec->Pt()>0.15 && abs(PID[j])==421 && V0MMult<16 && V0MMult>=12) hDZero0->Fill(vec->Pt());
            if(abs(vec->Eta())<2.0 && vec->Pt()>0.15 && abs(PID[j])==421 && V0MMult<12 && V0MMult>=9) hDZero1->Fill(vec->Pt());
            if(abs(vec->Eta())<2.0 && vec->Pt()>0.15 && abs(PID[j])==421 && V0MMult<9 && V0MMult>=6) hDZero2->Fill(vec->Pt());

            if(abs(vec->Eta())<2.0 && vec->Pt()>0.15 && abs(PID[j])==4122 && V0MMult<16 && V0MMult>=12) hlambc0->Fill(vec->Pt());
            if(abs(vec->Eta())<2.0 && vec->Pt()>0.15 && abs(PID[j])==4122 && V0MMult<12 && V0MMult>=9) hlambc1->Fill(vec->Pt());
            if(abs(vec->Eta())<2.0 && vec->Pt()>0.15 && abs(PID[j])==4122 && V0MMult<9 && V0MMult>=6) hlambc2->Fill(vec->Pt());

             if(abs(vec->Eta())<2.0 && vec->Pt()>0.15 && (PID[j])==443 && V0MMult<16 && V0MMult>=12) hJsi0->Fill(vec->Pt());
            if(abs(vec->Eta())<2.0 && vec->Pt()>0.15 && (PID[j])==443 && V0MMult<12 && V0MMult>=9) hJsi1->Fill(vec->Pt());
            if(abs(vec->Eta())<2.0 && vec->Pt()>0.15 && (PID[j])==443 && V0MMult<9 && V0MMult>=6) hJsi2->Fill(vec->Pt());
            
          
          
          


            // if(abs(vec->Eta())<2.0 && vec->Pt()>0.15 && abs(PID[j])==411) hDp->Fill(vec->Pt());
            // if(abs(vec->Eta())<2.0 && vec->Pt()>0.15 && abs(PID[j])==421) hDZero->Fill(vec->Pt());
            // if(abs(vec->Eta())<2.0 && vec->Pt()>0.15 && abs(PID[j])==4122) hlambc->Fill(vec->Pt());
            // if(abs(vec->Eta())<2.0 && vec->Pt()>0.15 && PID[j]==443) hJsi->Fill(vec->Pt());


            vec->Clear();

           
          
                       
        } // track loop ends
    }

// hDs0->SetMarkerStyle(20);
// hDs0->SetMarkerSize(1.5);

// hDs1->SetMarkerStyle(21);
// hDs1->SetMarkerSize(1.5);

// hDs2->SetMarkerStyle(22);
// hDs2->SetMarkerSize(1.5);

// hDZero->SetMarkerStyle(24);
// hDZero->SetMarkerSize(1.5);
// hlambc->SetMarkerStyle(26);
// hlambc->SetMarkerSize(1.5);

// hJsi->SetMarkerStyle(28);
// hJsi->SetMarkerSize(1.5);

// cout<<"Total Event: "<<nevents/100<<" Selected Events: "<<counter<<endl;

for(int bin=1; bin<=XBINS; bin++)
{
    hDs0->SetBinContent(bin, hDs0->GetBinContent(bin)/hDs0->GetBinWidth(bin));
    hDs1->SetBinContent(bin, hDs1->GetBinContent(bin)/hDs1->GetBinWidth(bin));
    hDs2->SetBinContent(bin, hDs2->GetBinContent(bin)/hDs2->GetBinWidth(bin));

   hDp0->SetBinContent(bin, hDp0->GetBinContent(bin)/hDp0->GetBinWidth(bin));
    hDp1->SetBinContent(bin, hDp1->GetBinContent(bin)/hDp1->GetBinWidth(bin));
    hDp2->SetBinContent(bin, hDp2->GetBinContent(bin)/hDp2->GetBinWidth(bin));

   hDZero0->SetBinContent(bin, hDZero0->GetBinContent(bin)/hDZero0->GetBinWidth(bin));
    hDZero1->SetBinContent(bin, hDZero1->GetBinContent(bin)/hDZero1->GetBinWidth(bin));
    hDZero2->SetBinContent(bin, hDZero2->GetBinContent(bin)/hDZero2->GetBinWidth(bin));

   hlambc0->SetBinContent(bin, hlambc0->GetBinContent(bin)/hlambc0->GetBinWidth(bin));
    hlambc1->SetBinContent(bin, hlambc1->GetBinContent(bin)/hlambc1->GetBinWidth(bin));
    hlambc2->SetBinContent(bin, hlambc2->GetBinContent(bin)/hlambc2->GetBinWidth(bin));

   hJsi0->SetBinContent(bin, hJsi0->GetBinContent(bin)/hJsi0->GetBinWidth(bin));
    hJsi1->SetBinContent(bin, hJsi1->GetBinContent(bin)/hJsi1->GetBinWidth(bin));
    hJsi2->SetBinContent(bin, hJsi2->GetBinContent(bin)/hJsi2->GetBinWidth(bin));
   
    // hDp->SetBinContent(bin, hDp->GetBinContent(bin)/hDp->GetBinWidth(bin));
    // hDZero->SetBinContent(bin, hDZero->GetBinContent(bin)/hDZero->GetBinWidth(bin));
    // hlambc->SetBinContent(bin, hlambc->GetBinContent(bin)/hlambc->GetBinWidth(bin));
    // hJsi->SetBinContent(bin, hJsi->GetBinContent(bin)/hJsi->GetBinWidth(bin));
}

hDs0->Scale(1.0/(counter*4.0));
hDs1->Scale(1.0/(counter*4.0));
hDs2->Scale(1.0/(counter*4.0));

hDp0->Scale(1.0/(counter*4.0));
hDp1->Scale(1.0/(counter*4.0));
hDp2->Scale(1.0/(counter*4.0));



hDZero0->Scale(1.0/(counter*4.0));
hDZero1->Scale(1.0/(counter*4.0));
hDZero2->Scale(1.0/(counter*4.0));

hlambc0->Scale(1.0/(counter*4.0));
hlambc1->Scale(1.0/(counter*4.0));
hlambc2->Scale(1.0/(counter*4.0));

hJsi0->Scale(1.0/(counter*4.0));
hJsi1->Scale(1.0/(counter*4.0));
hJsi2->Scale(1.0/(counter*4.0));


    // pTsp->Draw();
    // hDs0->Draw("pesame");
    // hDs1->Draw("pesame");
    // hDs2->Draw("pesame");
    
    //  pTsp1->Draw();
    // hDp0->Draw("pesame");
    // hDp1->Draw("pesame");
    // hDp2->Draw("pesame");
    
    //  pTsp2->Draw();
    // hDZero0->Draw("pesame");
    // hDZero1->Draw("pesame");
    // hDZero2->Draw("pesame");
    
    //  pTsp3->Draw();
    // hlambc0->Draw("pesame");
    // hlambc1->Draw("pesame");
    // hlambc2->Draw("pesame");
    
    //  pTsp4->Draw();
    // hJsi0->Draw("pesame");
    // hJsi1->Draw("pesame");
    // hJsi2->Draw("pesame");
    
   
    
    //  hDsm->Draw("pesame");
    //  hDp->Draw("pesame");
    // //  hDm->Draw("pesame");
    //  hDZero->Draw("pesame");
    // //  hDZerob->Draw("pesame");
    //   hlambc->Draw("pesame");
    // //  hlambcm->Draw("pesame");
    //  hJsi->Draw("pesame");

  TFile *f1 = new TFile("spectra_plot.root", "recreate"); //------- Name Change
    hDs0->Write("DsM1");
    hDs1->Write("DsM2"); 
    hDs2->Write("DsM3"); 
   
    hDp0->Write("DpM1");
    hDp1->Write("DpM2"); 
    hDp2->Write("DpM3"); 
   
    hDZero0->Write("DZeroM1");
    hDZero1->Write("DZeroM2"); 
    hDZero2->Write("DZeroM3"); 
   
    hlambc0->Write("lambcM1");
    hlambc1->Write("lambcM2"); 
    hlambc2->Write("lambcM3"); 
   
    hJsi0->Write("JsiM1");
    hJsi1->Write("JsiM2"); 
    hJsi2->Write("JsiM3"); 
   
//   hDp->Write("Dp");
//   hDZero->Write("DZero");
//   hlambc->Write("lambc");
//   hJsi->Write("Jsi");

    f1->Close();

    // c->SaveAs("DsMultwise.pdf");
}