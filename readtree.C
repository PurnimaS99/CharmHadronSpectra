void readtree()
{
    TFile *f = TFile::Open("/home/puri/pythia8308/examples/practice/pp_13TeV_317843104.root");

    TCanvas *c = new TCanvas("c","c", 750,600);
    c->Draw();

    const int n=60000;

    int ntrack=0,PID[n]={0},charge[n]={0},V0M=0;
    double px[n]={0},py[n]={0},pz[n]={0},pT[n]={0},mass[n]={0};
    double eta[n]={0},rap[n]={0},phi[n]={0};
    double spherocity(0);

    TTree *theTree = (TTree*)f->Get("t");
	  
	theTree->SetBranchAddress("ntrack", &ntrack);  //ntrack is the size of the tree (fill only final chargedparticles)  
	theTree->SetBranchAddress("PID", PID);
	// theTree->SetBranchAddress("charge",charge);
	theTree->SetBranchAddress("px",px);
	theTree->SetBranchAddress("py",py);
	theTree->SetBranchAddress("pz",pz);
    theTree->SetBranchAddress("V0MMult",&V0M);
	// theTree->SetBranchAddress("mass",mass);
	// theTree->SetBranchAddress("eta",eta);
	// theTree->SetBranchAddress("pT",pT);  
	// theTree->SetBranchAddress("rap",rap);       
	// theTree->SetBranchAddress("phi",phi);
    // theTree->SetBranchAddress("spherocity", &spherocity); 

    // TH1D *h1 = new TH1D("h", "h", 100, 0, 400);
    // h1->SetLineColor(kRed + 2);
    // h1->SetMarkerSize(2);
     TH2D *h1 = new TH2D("h", "h", 100, 0, 250, 100, 0,100 );
    h1->SetLineColor(kRed + 2);
    h1->SetMarkerSize(2);

    // TH1D *h1 = new TH1D("h", "h", 100, binns); // for which Double_t binns[101]={0, 1, 2, 3...100};

    const Int_t nevents = (Int_t)theTree->GetEntries();
    // int nevents = 1000000;

    for (int i = 0; i < nevents; i++)
    {
        theTree->GetEntry(i);
        h1->Fill(ntrack, V0M);
                // for (int j = 0; j < ntrack; j++)
        // {
            
        //     h1->Fill(eta[j]);
        // }
    }

    h1->Draw("lpsame");

    c->SaveAs("V0Mandtrackcoreln.pdf");

}